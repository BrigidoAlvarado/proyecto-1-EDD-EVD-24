//
// Created by brigidoalvarado on 13/12/24.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <queue>
using namespace std;

template <class T>
class NodoBin {
public:
    NodoBin<T> *izq ;
    NodoBin<T> *der ;
    T info ;

    NodoBin() ;
    NodoBin(T info);
    virtual ~NodoBin() ;
} ;

template <class T>
class ArbolBin {
public:
    ArbolBin();
    virtual ~ArbolBin();
    void recNiveles()
    {
        if (!raiz) return;

        std::queue<NodoBin<T>*> cola;
        cola.push(raiz);

        while (!cola.empty())
        {
            NodoBin<T>* actual = cola.front();
            cola.pop();

            visita(actual);

            if (actual->izq) {
                cola.push(actual->izq);
            }
            if (actual->der) {
                cola.push(actual->der);
            }
        }
    } ;

protected:
    NodoBin<T> *raiz ;
    virtual void visita (NodoBin<T> *n)  {
       cout<<n->info<<", " ;
    }
} ;

int main()
{
    cout<<"hola mundo"<<endl ;
    return 0;
}
#endif //BINARYTREE_H
