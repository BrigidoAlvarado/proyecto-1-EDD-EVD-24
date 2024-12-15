//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/PrincipalMenu.h"
#include <limits>
#include <iostream>
#include <stdexcept>
using namespace std;

const string PrincipalMenu::ADMIN_NAME = "admin";
const string PrincipalMenu::ADMIN_USER_NAME = "admin";

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
    cout << "en login";
}

void PrincipalMenu::validateAdminCredentials(string name, string password)
{

}
