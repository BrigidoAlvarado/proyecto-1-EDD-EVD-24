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


User* SparseMatrix::getUser(string name, string password, string department, string company)
{
    //primero se busca el departamento
    MatrixNode *auxDepartment = hHeader;
    while (auxDepartment != nullptr)
    {
        if (auxDepartment->getKey() == department)
        {
            //buscar la compania
            MatrixNode *user = auxDepartment->getdown();
            while (user != nullptr)
            {
                MatrixNode *userCompany = goToCompany(user);
                if (userCompany->getKey() == company)
                {
                    //se busca el nombre de usuario y la contrasenia
                    MatrixNode *posiblyUser = user;
                    while (posiblyUser != nullptr)
                    {
                        if (posiblyUser->getKey() == name && posiblyUser->getuser()->getPassword() == password)
                        {
                            return posiblyUser->getuser();
                        }
                        posiblyUser = posiblyUser->getbackward();
                    }
                }
                user = user->getdown();
            }
        }
        auxDepartment = auxDepartment->getnext();
    }
    return nullptr;
}

void SparseMatrix::insertUser(User*& user, string key, string department, string company)
{
    MatrixNode *departmentHeader = nullptr;
    MatrixNode *companyHeader = nullptr;
    MatrixNode *newUser = new MatrixNode(key, user);

    //Caso en que la matriz esta vacia
    if (isEmpty())
    {
        //se crean las cabeceras
        departmentHeader = insertHHeader(department);
        companyHeader = insertVHeader(company);
        //se inserta el usuario al final de las nuevas cabeceras
        insertAtTheEnd(newUser, departmentHeader, companyHeader);
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
        insertAtTheEnd(newUser, departmentHeader, companyHeader);
        return;
    }

    //Caso en que la compania no se encuentra y el departameto si
    if (companyHeader == nullptr)
    {
        companyHeader = insertVHeader(company);
        insertAtTheEnd(newUser, departmentHeader, companyHeader);
        return;
    }

    //Caso en que el departamento hay que crearlo y la compania no
    if (departmentHeader == nullptr)
    {
        departmentHeader = insertHHeader(department);
        insertAtTheEnd(newUser, departmentHeader, companyHeader);
        return;
    }

    //Insertar el usuario detras de otro con las mismas cabeceras
    MatrixNode *lastUser = search(key ,departmentHeader, companyHeader);
    if (lastUser != nullptr)
    {
        insertBack(newUser, lastUser);
        return;
    }

    //Insertar el usuario en medio verticalmente
    MatrixNode *hAux = departmentHeader->getdown();
    MatrixNode *userVHeader = nullptr;
    bool down = false;
    while ( hAux != nullptr )
    {
        userVHeader = goToCompany(hAux);
        down = below( userVHeader, company);
        if (!down) break;

        hAux = hAux->getdown();
    }
    if (down)
    {
        insertAtTheEndOfDepartment(newUser, departmentHeader);
    } else
    {
        insertAtTheHalfH(newUser, hAux);
    }

    //Insertar el usuario en medio horizontalmente
    MatrixNode *vAux = companyHeader->getnext();
    MatrixNode *userHHeader = nullptr;
    bool right = false;

    while ( vAux != nullptr )
    {
        userHHeader = goToDepartment(vAux);
        right = futherRight(userHHeader, department);
        if (!right)break;

        vAux = vAux->getnext();
    }

    if (right)
    {
        insertAtTheEndOfCompany(newUser, vHeader);
    }
    else
    {
        insertAtTheHalfV(newUser, vAux);
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

void SparseMatrix::insertAtTheEnd(MatrixNode *newUser, MatrixNode* department, MatrixNode* company)
{
    insertAtTheEndOfDepartment(newUser, department);
    insertAtTheEndOfCompany(newUser, company);
}

void SparseMatrix::insertAtTheEndOfDepartment(MatrixNode* user, MatrixNode* department)
{
    MatrixNode *aux = department;
    //Buscar el ultimo nodo conectado a el departamento
    while (aux->getdown() != nullptr)
    {
        aux = aux->getdown();
    }
    //crear la coneccion con el departamento
    aux->setDown(user);
    user->setup(aux);
}

void SparseMatrix::insertAtTheEndOfCompany(MatrixNode* user, MatrixNode* company)
{
    MatrixNode *aux = company;
    //Buscarl el ultimo nodo conectado a la commpania
    while (aux->getnext() != nullptr)
    {
        aux = aux->getnext();
    }
    //Crear la coneccion con la compania
    aux->setnext(user);
    user->setprev(aux);
}

void SparseMatrix::insertAtTheHalfV(MatrixNode* user, MatrixNode* vertical)
{
    vertical->getprev()->setnext(user);
    user->setnext(vertical);
    user->setprev(vertical->getprev());
    vertical->setprev(user);
}

void SparseMatrix::insertAtTheHalfH(MatrixNode* user, MatrixNode* horizontal)
{
    horizontal->getup()->setDown(user);
    user->setDown(horizontal);
    user->setup(horizontal->getup());
    horizontal->setup(user);
}

void SparseMatrix::insertBack(MatrixNode* user, MatrixNode* forward)
{
    user->setForward(forward);
    forward->setBackward(user);
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

MatrixNode* SparseMatrix::goToBack(MatrixNode* node, string userName)
{
    MatrixNode *aux = node;
    while (aux->getbackward() != nullptr)
    {
        if (aux->getKey() == userName)
        {
            std::cout << "  El nombre de usuario: " << userName << endl;
            std::cout << "  Ya se encuentra registrado en este departamento y esta compania..." << endl;
            return nullptr;
        }
        aux = aux->getbackward();
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

MatrixNode* SparseMatrix::search(string key, MatrixNode* department, MatrixNode* company)
{
    MatrixNode *auxDepartment = department->getdown();

    while (auxDepartment != nullptr)
    {
        MatrixNode *auxCompany = goToCompany(auxDepartment);
        if (auxCompany->getKey() == company->getKey())
        {
            return goToBack(auxDepartment, key);
        }
        auxDepartment = auxDepartment->getdown();
    }
return auxDepartment;
}

bool SparseMatrix::isEmpty()
{
    return (this->hHeader == nullptr && this->vHeader == nullptr);
}

bool SparseMatrix::below(MatrixNode* company, string key)
{
    MatrixNode *aux = company;
    while (aux != nullptr)
    {
        if (aux->getKey() == key)
        {
            return true;
        }
        aux = aux->getdown();
    }
    return false;
}

bool SparseMatrix::futherRight(MatrixNode* department, string key)
{
    MatrixNode *aux = department;
    while (aux != nullptr)
    {
        if (aux->getKey() == key)
        {
            return true;
        }
        aux = aux->getnext();
    }
    return false;
}