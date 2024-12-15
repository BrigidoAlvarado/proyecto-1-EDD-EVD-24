//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/AdminMenu.h"

#include <iostream>
#include <ostream>
#include <limits>
#include <stdexcept>

#include "../includes/PrincipalMenu.h"
using namespace std;

AdminMenu::AdminMenu()
{
    this->admin = new Admin();
}

void AdminMenu::displayMenu()
{
    try
    {
        cout << endl;
        cout << "%%%%%%%%%%%%%%%%%%% Menú Administrador %%%%%%%%%%%%%%%%%%%" << endl;
        cout << "%% 1. Registrar Usuario" << endl;
        cout << "%% 2. Reporte Matriz Dispersa" << endl;
        cout << "%% 9. Cerrar Sesion" << endl;
        int option;
        cout << "  Ingrese una opcion: "; cin >> option;
        if (cin.fail()) throw invalid_argument("La opcion ingresada no es numerica");

        Admin admin = Admin();
        switch (option)
        {
            case 1:
                admin.enterUser();
                break;
            case 2:
                cout << "Reporte de la matriz no disponible" << endl;
                break;
            case 9:
                {
                    auto principalMenu = PrincipalMenu();
                    principalMenu.displayMenu();
                    break;
                }
            default:
                throw invalid_argument("  El valor ingresado no esta dentro de las opciones");
        }
    } catch (const invalid_argument& e)
    {
        cout << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << e.what() << endl;
        cout << "  Presione enter para continuar...";
        cin.get();
        displayMenu();
    }
}