//
// Created by brigidoalvarado on 15/12/24.
//
#include "../../includes/sparseMatrix/SparseMatrix.h"

#include "../../includes/Tools.h"

SparseMatrix::SparseMatrix()
{
    this->hHeader = nullptr;
    this->vHeader = nullptr;
}

void SparseMatrix::insertUser(User*& user, string key, string department, string company)
{
    if (isEmpty())
    {
        //se crean las cabeceras
        MatrixNode *departmentHeader = insertHHeader(department);
        MatrixNode *companyHeader = insertVHeader(company);
        //se inserta el usuario al final de las nuevas cabeceras
        insertAtTheEnd(user, departmentHeader, companyHeader, key);
        cout << "  Se inserto al final";
    }

    cout << "  Usuario ingresado exitosamente" << endl;
    Tools tools = Tools();
    tools.pressStart();
}


MatrixNode* SparseMatrix::searchDeparment(string department)
{
    if (SparseMatrix::isEmpty())
    {
        return nullptr;
    }

    MatrixNode *aux = hHeader;

    while (aux != nullptr)
    {
        if (aux->getKey() == department)
        {
            return aux;
        } else
        {
            aux = aux->getnext();
        }
    }
    return nullptr;
}

MatrixNode* SparseMatrix::searchCompany(string company)
{
    if (SparseMatrix::isEmpty())
    {
        return nullptr;
    }

    MatrixNode *aux = vHeader;
    while (aux != nullptr )
    {
        if (aux->getKey() == company)
        {
            return aux;
        } else
        {
            aux = aux->getdown();
        }
    }
    return nullptr;
}

void SparseMatrix::insertAtTheEnd(User*& user, MatrixNode* department, MatrixNode* company, string key)
{
    MatrixNode *newUser = new MatrixNode(key, user);

    MatrixNode *hAux = department;
    MatrixNode *vAux = company;

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

    MatrixNode *newDepartment = new MatrixNode(department);
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

    MatrixNode *newCompany = new MatrixNode(company);
    aux -> setDown(newCompany);
    return newCompany;
}


bool SparseMatrix::isEmpty()
{
    return (this->hHeader == nullptr && this->vHeader == nullptr);
}


