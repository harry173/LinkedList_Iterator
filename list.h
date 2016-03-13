#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template<typename T>
class Lista {
private:
    Lista* urm;
    Lista* prev;

    class Iterator{
        const Lista* lst;
    public:
        Iterator(Lista *l){
            this->l = l;
        }
        T& operator *(){
            return data;
        }
        T* operator ->(){
            return &data;
        }
        Iterator operator ++(){
            return Iterator(urm);
        }
        Iterator operator ++(int){
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
    };

public:
    T data;
    typedef Iterator iterator;
    Lista(){
        data = 0;
        urm = NULL;
        prev = NULL;
    }
    Lista(const T& data) {
        this->data = data;
        this->urm = NULL;
        this->prev = NULL;
    }

    /*~Lista() {
        Lista* current = this;
        Lista* next;

        while(current->urm != NULL) {
            next = current->urm;
            delete current;
            current = next;
        }

        delete current;
    } */

    void push_back(const T& data) {
        Lista* aux = this;
        while(aux->urm != NULL)
            aux = aux->urm;
        aux->urm = new Lista(data);
        aux->urm->prev = aux;
    }

    void push_front(const T& data) {
        Lista* aux = this;
        while(aux->prev != NULL)
            aux = aux->prev;

        aux->prev = new Lista(data);
        aux->prev->urm = aux;
    }

    void insert(const T& data, int index) {
        int i;
        Lista* aux = this;
        Lista* newNode;
        for(i=1; i<index; i++)
            if(aux->urm == NULL){
                std::cout<<"Index is out of range"<<std::endl;
                return;
            }
            else
                aux = aux->urm;

        newNode = new Lista(data);
        newNode->urm = aux;
        newNode->prev = aux->prev;

        if(aux->prev != NULL)
            aux->prev->urm = newNode;

        aux->prev = newNode;
    }

    void remove(int index) {
        int i;
        Lista* aux = this;
        for(i=1; i<index; i++)
            if(aux->urm == NULL){
                std::cout<<"No element exists at index"<<std::endl;
                return;
            }
            else
                aux = aux->urm;

        if(aux->prev != NULL)
            aux->prev->urm = aux->urm;
        if(aux->urm != NULL)
            aux->urm->prev = aux->prev;
        delete aux;

    }

    void clearList() {
        Lista* current = this;
        Lista* next;

        while(current->urm != NULL) {
            next = current->urm;
            delete current;
            current = next;
        }

        delete current;
    }

    Lista* getNext() {
        return this->urm;
    }

    Lista* getPrev() {
        return this->prev;
    }

    iterator begin(){
        return Iterator(this);
    }
    iterator end(){
        Lista* aux = this;
        while(aux->urm != NULL)
            aux = aux->urm;
        return Iterator(aux);
    }
};

#endif // LIST_H_INCLUDED
