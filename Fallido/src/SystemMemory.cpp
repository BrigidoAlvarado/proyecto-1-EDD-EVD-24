//
// Created by brigidoalvarado on 8/12/24.
//
#include "../includes/SystemMemory.h"
#include "../includes/SparseMatrix/SparseMatrix.h"

SystemMemory::SystemMemory()
{
    this->sparseMatrix = new SparseMatrix();
}

SystemMemory::~SystemMemory()
{
    delete this;
}

SparseMatrix* SystemMemory::getSparseMatrix()
{
    return this->sparseMatrix;
}