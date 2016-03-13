#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    Lista<int> *lista = new Lista<int>(1);
    Lista<int> *aux;
    int i;
    for(i=2; i<=10; i++)
        lista->push_back(i);

    lista->insert(15, 4);
    lista->remove(7);


    aux = lista;
    for(i=1; i<=10; i++)
    {
        cout<<aux->data<<" ";
        aux = aux->getNext();
    }

    lista->clearList();

    /*
    iterator<int> iEnd = lista.end();
    iterator<int> it = lista.begin();
    while(it != iEnd) {
        cout<<*it<<endl;
        ++it;
    }
    */
    return 0;
}
