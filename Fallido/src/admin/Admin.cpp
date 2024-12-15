//
// Created by brigidoalvarado on 8/12/24.
//
#include <iostream>
#include "../../includes/admin/Admin.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

Admin::Admin(SystemMemory* systemMemory)
{
    this->systemMemory = systemMemory;
}

Admin::~Admin()
{
    delete this;
}

void Admin::registerUser()
{
    string name, password, fullName, department, company;
    cout << endl;
    cout << "  REGISTRAR NUEVO USUARIO" << endl;
    cout << "  Nombre: "; cin >> name; cout << endl;
    cout << "  Contraseña : "; cin >> password; cout << endl;
    cout << "  Nombre Completo: "; cin >> fullName; cout << endl;
    cout << "  Compania: "; cin >> company; cout << endl;

    //Se construye un usuario con los datos ingresados
    User *user = new User(systemMemory);
    user->setName(name);
    user->setPassword(password);
    user->setFullName(fullName);

    //se accede a la matriz dispersa y se inserta un nuevo usuario
    systemMemory->getSparseMatrix()->insert(user, department, company);

}

