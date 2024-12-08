//
// Created by brigidoalvarado on 8/12/24.
//

#include "../../includes/admin/AdminMenu.h"

#include <iostream>
#include <string>

using std:: string;
using std:: cout;
using std:: endl;
using std:: cin;

AdminMenu::AdminMenu(Admin* admin)
{
    this->admin = admin;
}

AdminMenu::~AdminMenu()
{
    delete this;
}

void AdminMenu::showMenu()
{
    cout << endl;
    cout << "%%%%%%%%%%%%%%%%%%% Menú Administrador %%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%% 1. Registrar Usuario" << endl;
    cout << "%% 2. Reporte Matriz Dispersa" << endl;
    cout << "%% 3. Reporte Activos Disponibles de un Departamento" << endl;
    cout << "%% 4. Reporte Activos Disponibles de una Empresa" << endl;
    cout << "%% 5. Reporte Transacciones" << endl;
    cout << "%% 6. Reporte Activos de un Usuario" << endl;
    cout << "%% 7. Activos rentados por un Usuario" << endl;
    cout << "%% 8. Odernar Transacciones" << endl;
    cout << "%% 9. Salir" << endl;
    cout << endl;
    int option;
    cout << "Ingrese una opcion: ";

    while (!(cin >> option)) {
        cout << "Entrada inválida. Por favor ingrese un número." << endl;
        cin.clear();
    }

    switch (option)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            cout << endl;
            cout << "######################## Opcion Invalida #################" << endl;
            cout << "  La opcion ingresada: " << option << " es invalida !!" << endl;
            cin.clear();
            showMenu();
    }
}


