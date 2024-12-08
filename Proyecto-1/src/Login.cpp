//
// Created by brigidoalvarado on 8/12/24.
//
#include "../includes/Login.h"

#include "../includes/admin/AdminMenu.h"
#include "../includes/admin/Admin.h"

using std:: string;
using std:: cout;
using std:: endl;
using std:: cin;

 const string Login::ADMIN_NAME = "admin";
 const string Login::ADMIN_PASSWORD = "admin";

Login::Login()
{
    this -> systemMemory = new SystemMemory();
}

Login::Login(SystemMemory *system_memory)
{
    this -> systemMemory = system_memory;
}

Login::~Login()
{
    delete this;
}


void Login::showMenu()
{
    cout << "%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%       Login      %%%%%%%%%%%%%%%%%%%%" << endl;
    cout << endl;
    cout << "__Ingresar Nombre de Usuario: ";
    string name;
    cin >> name;
    cout << endl;
    cout << "__Ingresar Contraseña: ";
    string password;
    cin >> password;
    validAdminCredentials(name, password);
    string department;
    cin >> department;
    string company;
    cin >> company;
    //validar usuario
}

void Login::validAdminCredentials(string name, string password)
{
    if (name == ADMIN_NAME && password == ADMIN_PASSWORD)
    {
        AdminMenu adminMenu = AdminMenu( new Admin(systemMemory) );
        adminMenu.showMenu();
    }
}

SystemMemory Login::getSystemMemory()
{
    return *systemMemory;
}


