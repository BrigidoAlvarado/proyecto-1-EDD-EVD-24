//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef SYSTEMMEMORY_H
#define SYSTEMMEMORY_H

#include <iostream>
#include "SparseMatrix/SparseMatrix.h"

using std::string;

class SparseMatrix;
class SystemMemory
{
private:
    SparseMatrix *sparseMatrix;
    //arbol avl
    //lista
public:
    SystemMemory();
    ~SystemMemory();
    //GETTERS
    SparseMatrix *getSparseMatrix();
    //SETTERS
};

#endif //SYSTEMMEMORY_H
