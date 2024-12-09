//
// Created by brigidoalvarado on 8/12/24.
//
#include "../../includes/SparseMatrix/SparseMatrix.h"

SparseMatrix::SparseMatrix()
{
    this->hHeader = nullptr;
    this ->vHeader = nullptr;
}

bool SparseMatrix::isEmpty()
{
    return (this->hHeader == nullptr && this->vHeader == nullptr);
}

MatrixNode* SparseMatrix::searchHHeader(string department)
{
    if (SparseMatrix::isEmpty())
    {
        return nullptr;
    }

    MatrixNode *aux = hHeader;

    while (aux != nullptr)
    {
        if (aux->getname() == department)
        {
            return aux;
        } else
        {
            aux = aux->getnext();
        }
    }
    return nullptr;
}

MatrixNode* SparseMatrix::searchVHeader(string company)
{
    if (SparseMatrix::isEmpty())
    {
        return nullptr;
    }

    MatrixNode *aux = vHeader;
    while (aux != nullptr )
    {
        if (aux->getname() == company)
        {
            return aux;
        } else
        {
            aux = aux->getdown();
        }
    }
    return nullptr;
}

void SparseMatrix::insert(User *user)
{
    if (SparseMatrix::isEmpty())
    {

    }
}

MatrixNode* SparseMatrix::insertHHeader(string department)
{
    MatrixNode *aux = hHeader;

    while (aux->getnext() != nullptr)
    {
        aux = aux->getnext();
    }

    MatrixNode *newDepartment = new MatrixNode();
    newDepartment->setName(department);
    aux->setnext(newDepartment);
    newDepartment->setprev(aux);
}

MatrixNode* SparseMatrix::insertVHeader(string company)
{
    MatrixNode *aux = vHeader;

    while (aux -> getdown() != nullptr)
    {
        aux = aux -> getdown();
    }

    MatrixNode *newCompany = new MatrixNode();
    newCompany->setName(company);
    aux -> setDown(newCompany);
}