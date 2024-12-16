//
// Created by brigidoalvarado on 8/12/24.
//
#include "../../includes/SparseMatrix/SparseMatrix.h"
#include "../../includes/SparseMatrix/MatrixNode.h"

SparseMatrix::SparseMatrix()
{
    this->hHeader = nullptr;
    this ->vHeader = nullptr;
}

void SparseMatrix::insert(User *user, string department, string company)
{
    //Caso en que la matriz esta vacia
    if (SparseMatrix::isEmpty())
    {
        //se crean las cabeceras
        MatrixNode *hHeader = insertHHeader( department);
        MatrixNode *vHeader = insertVHeader(company);
        //se inserta el nuevo usuario al final de cada cabecera
        insertAtTheEnd(user, hHeader, vHeader);
    }
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

void SparseMatrix::insertAtTheEnd(User *&user, MatrixNode* hHeader, MatrixNode* vHeader)
{
    MatrixNode *newUser = new MatrixNode(user);

    MatrixNode *hAux = hHeader;
    MatrixNode *vAux = vHeader;

    //Buscar el ultimo nodo conectado a el departamento
    while (hAux->getdown() != nullptr)
    {
        hAux = hAux->getdown();
    }
    //crear la coneccion con el departamento
    hAux->setDown(newUser);
    newUser->setup(hAux);

    //Buscarl el ultimo nodo conectado a la commpania
    while (vAux->getnext() != nullptr)
    {
        vAux = vAux->getnext();
    }
    //Crear la coneccion con la compania
    vAux->setnext(newUser);
    newUser->setprev(vAux);
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
    return newDepartment;
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
    return newCompany;
}