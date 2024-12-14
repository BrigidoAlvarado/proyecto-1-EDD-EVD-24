//
// Created by brigidoalvarado on 13/12/24.
//
#include <iostream>;
#include <queue>

using namespace std;

class NodoBinario {
    public:
    string valor ;
    NodoBinario *izq ;
    NodoBinario *der ;
} ;

class ArbolBinario {
public:
    ArbolBinario *copia( ) ;
private:
    NodoBinario *raíz ;
} ;

ArbolBinario *copia( )
{
    if (raiz == nullptr) return nullptr ;

    ArbolBinario *copia = new ArbolBinario();

    NodoBinario *aux = raiz;
    NodoBinario *auxIzq = nullptr ;
    NodoBinario *auxDer = nullptr ;

    if (raiz->izq != nullptr) auxIzq = raiz->izq ;
    if (raiz->der != nullptr) auxDer = raiz->der ;

    aux->izq = auxIzq;
    aux->der = auxDer;



}
