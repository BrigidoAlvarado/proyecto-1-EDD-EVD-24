//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/PrincipalMenu.h"
#include <limits>
#include <iostream>
#include <stdexcept>

#include "../includes/AdminMenu.h"
#include "../includes/UserMenu.h"
#include "../includes/Tools.h"
using namespace std;

const string PrincipalMenu::ADMIN_NAME = "admin";
const string PrincipalMenu::ADMIN_PASSWORD = "admin";

PrincipalMenu::PrincipalMenu()
{
    this->matrix = new SparseMatrix();
}

PrincipalMenu::PrincipalMenu(SparseMatrix* matrix)
{
    this->matrix = matrix;
}

void PrincipalMenu::displayMenu()
{
    try
    {
        cout << endl;
        cout << "%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%" <<endl;
        cout << "  1) Login" << endl;
        cout << "  2) Salir" << endl;
        int option;
        cout << "  Ingrese una opcion: "; cin >> option;
        if (cin.fail())
        {
            throw invalid_argument("La opcion ingresada no es numerica");
        }
        switch(option)
        {
        case 1:
            displayLoginMenu();
            break;
        case 2:
            exit(0);
        default:
            throw invalid_argument("La opcion ingresada es invalida");
        }
    } catch(const invalid_argument& e)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;
        cout << e.what() << endl;
        cout << "  Enter para continuar...";
        cin.get();
        displayMenu();
    }
}

void PrincipalMenu::displayLoginMenu()
{
    cout << endl;
    cout << "%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%       Login      %%%%%%%%%%%%%%%%%%%%" << endl;
    cout << endl;
    cout << "  Ingresar Nombre de Usuario: ";
    string name;
    cin >> name;
    cout << "  Ingresar Contraseña: ";
    string password;
    cin >> password;
    //valida si la cuenta pertenece al administrador
    if (validateAdminCredentials(name, password))
    {
        return;
    }
    string department;
    cout << "  Ingresar Departemento: " ; cin >> department;
    string company;
    cout << "  Ingresar Compania: "; cin >> company;
    //validar inicio de sesion de usuario
    User *user = matrix->getUser(name, password, department, company);

    if (user != nullptr)
    {
        UserMenu *userMenu = new UserMenu(user);
        userMenu->displayMenu();
    } else
    {
        cout << "  Usuario no encontrado" << endl;
        Tools::pressStart(true);
    }
    displayMenu();
}

bool PrincipalMenu::validateAdminCredentials(string name, string password)
{
    if (name == ADMIN_NAME && password == ADMIN_PASSWORD)
    {
        AdminMenu adminMenu = AdminMenu(new Admin(matrix));
        adminMenu.displayMenu();
        displayMenu();
        return true;
    }
    return false;
}

void PrincipalMenu::init()
{
    User *elian_estrada = new User();
    elian_estrada->setPassword("1234");
    elian_estrada->setFullName("Elian Estrada");
    matrix->insertUser(elian_estrada, "elian_estrada", "guatemala", "igss");
}

