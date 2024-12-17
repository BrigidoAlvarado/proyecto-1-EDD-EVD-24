//
// Created by brigidoalvarado on 16/12/24.
//
#include "../includes/UserMenu.h"
#include <iostream>
#include <limits>
#include "../includes/Tools.h"
using namespace std;

UserMenu::UserMenu(User* user)
{
    this->user = user;
}

void UserMenu::displayMenu()
{
    try
    {
        cout << endl;
        cout << "%%%%%%%%%%%%%%%%%%%- Nombre de Usuario -%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "%%%%%%%%%%%%%%%%%%%  1. Agregar Activo   %%%%%%%%%%%%%%%%%%%" << endl;
        cout << "%%%%%%%%%%%%%%%%%%%  2. Eliminar Activo  %%%%%%%%%%%%%%%%%%%" << endl;
        cout << "%%%%%%%%%%%%%%%%%%%  7. Cerrar Sesión    %%%%%%%%%%%%%%%%%%%"  << endl;
        int option = 0;
        cout << "  Ingresar opcion: "; cin >> option; cout << endl;
        if (cin.fail()) throw invalid_argument("  La opcion ingresada no es numerica");

        switch (option)
        {
            case 1:
                insertAsset();
                displayMenu();
                break;
            case 2:
                deleteAsset();
                displayMenu();
                break;
            case 7:
                break;
            default:
                throw invalid_argument("  La opcion ingresada no esta fuera de los parametros admitidos");
        }
    }catch ( const invalid_argument &e)
    {
        cout << endl;
        cout << e.what() << endl;
        Tools::pressStart(true);
    }
}

void UserMenu::insertAsset()
{
    cin.clear();
    cin.ignore();
    cout << "%%%%%%%%%%%%%%%%%%%% Agregar Activo %%%%%%%%%%%%%%%%%%%%" << endl;
    string name;
    cout << " ->Ingresar nombre del activo: "; getline(cin, name);
    string description;
    cout << " ->Ingresar descripcion: "; getline(cin, description);
    int rentTime;
    cout << " ->Ingresar maximo tiempo de renta: "; cin >> rentTime;
    string id = Tools::idGenerator();

    //guardar nuevo activo
    Asset *asset = new Asset();
    asset->setDescription(description);
    asset->setId(id);
    asset->setRentTime(rentTime);
    asset->setName(name);

    user->getAssets()->insert(id, asset);
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "  Se guardo el nuevo activo con..." << endl;
    cout << "------------------------------------------" << endl;
    cout << "  ID : " << id << endl;
    cout << "  Nombre: " << name << endl;
    cout << "  Descripcion: " << description << endl;
    cout << "  Maximo tiempo de renta: " << rentTime << endl;
    cout << "------------------------------------------" << endl;

    Tools::pressStart(true);
}

void UserMenu::deleteAsset()
{
    cout << endl;
    cout << "  Ingrese el ID de un activo para eliminarlo" << endl;
    user->getAssets()->printTree();
    string id;
    cout << " ->Ingresar id: "; cin >> id;
    cout << endl;
    user->getAssets()->deleteAsset(id);
    cout << endl;
    cout << " Activo con ID: " << id << " eliminado exitosamente" << endl;
    Tools::pressStart(true);
}