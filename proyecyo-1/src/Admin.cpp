//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/Admin.h"
#include "../includes/User.h"
#include <iostream>
using namespace std;

void Admin::enterUser()
{
    cout << endl;
    cout << "%%%%%%%%%%%%%%%%% Ingresar Nuevo Usuario %%%%%%%%%%%%%%%%%" << endl;
    string name;
    cout << " -> Nombre: "; cin >> name; cout << endl;
    string password;
    cout << " -> Contraseña: "; cin >> password; cout << endl;
    string fullName;
    cout << " -> Nombre Completo: "; cin >> fullName; cout << endl;
    string department;
    cout << " -> Departmento: "; cin >> department; cout << endl;
    string company;
    cout << " -> Compania: "; cin >> company; cout << endl;

    //se crea un objeto de tipo usuario
    User *user = new User();
    user->setName(name);
    user->setPassword(password);
    user->setFullName(fullName);

    //se inserta el nuevo usuario
}