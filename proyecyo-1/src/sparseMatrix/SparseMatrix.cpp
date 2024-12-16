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

MatrixNode* SparseMatrix::getHHeader()
{
    return this->hHeader;
}

MatrixNode* SparseMatrix::getVHeader()
{
    return this->vHeader;
}

void SparseMatrix::insertUser(User*& user, string key, string department, string company)
{
    MatrixNode *departmentHeader = nullptr;
    MatrixNode *companyHeader = nullptr;

    //Caso en que la matriz esta vacia
    if (isEmpty())
    {
        //se crean las cabeceras
        departmentHeader = insertHHeader(department);
        companyHeader = insertVHeader(company);
        //se inserta el usuario al final de las nuevas cabeceras
        insertAtTheEnd(user, departmentHeader, companyHeader, key);
        return;
    }

    //Se busca si existen cabeceras con el los parametros ingresados
    departmentHeader = searchDeparment(department);
    companyHeader = searchCompany(company);

    //Caso en que no se ecuentran las cabeceras buscadas
    if (departmentHeader == nullptr && companyHeader == nullptr)
    {
        //se crean las cabeceras en la matriz
        departmentHeader = insertHHeader(department);
        companyHeader = insertVHeader(company);
        //se inserta el usuario al final de las cabeceras
        insertAtTheEnd(user, departmentHeader, companyHeader, key);
        return;
    }

    //Caso en que la compania no se encuentra y el departameto si
    if (companyHeader == nullptr)
    {
        companyHeader = insertVHeader(company);
        insertAtTheEnd(user, departmentHeader, companyHeader, key);
        return;
    }

    //Caso en que el departamento hay que crearlo y la compania no
    if (departmentHeader == nullptr)
    {
        departmentHeader = insertHHeader(department);
        insertAtTheEnd(user, departmentHeader, companyHeader, key);
        return;
    }
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

void SparseMatrix::insertAtTheEndOfDepartment(User*& user, MatrixNode* department, string key)
{
    cout << "nothing";
}

void SparseMatrix::insertAtTheEndOfCompany(User*& user, MatrixNode* company, string key)
{
    cout << "nothing";
}

MatrixNode* SparseMatrix::goToDepartment(MatrixNode* node)
{
    MatrixNode *aux = node;

    while (aux->getup() != nullptr)
    {
        aux = aux->getup();
    }
    return aux;
}

MatrixNode* SparseMatrix::goToCompany(MatrixNode* node)
{
    MatrixNode *aux = node;

    while (aux->getprev() != nullptr)
    {
        aux = aux->getprev();
    }
    return aux;
}

MatrixNode* SparseMatrix::insertHHeader(string department)
{
    MatrixNode *newDepartment = new MatrixNode(department);

    if (this->hHeader == nullptr)
    {
        this->hHeader = newDepartment;
        return newDepartment;
    }

    MatrixNode *aux = this->hHeader;

    while (aux->getnext() != nullptr)
    {
        aux = aux->getnext();
    }

    aux->setnext(newDepartment);
    newDepartment->setprev(aux);
    return newDepartment;
}

MatrixNode* SparseMatrix::insertVHeader(string company)
{
    MatrixNode *newCompany = new MatrixNode(company);

    if (this->vHeader == nullptr)
    {
        this->vHeader = newCompany;
        return newCompany;
    }

    MatrixNode *aux = this->vHeader;

    while (aux -> getdown() != nullptr)
    {
        aux = aux -> getdown();
    }

    aux -> setDown(newCompany);
    return newCompany;
}

bool SparseMatrix::isEmpty()
{
    return (this->hHeader == nullptr && this->vHeader == nullptr);
}