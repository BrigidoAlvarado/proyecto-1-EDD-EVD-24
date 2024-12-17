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

    Asset *a1 = new Asset();
    //a1->setId(Tools::idGenerator());
    a1->setName("madera");
    a1->setDescription("madera para albañil");
    a1->setRentTime(20);
    elian_estrada->getAssets()->insert( Tools::idGenerator(),a1);

    Asset *a2 = new Asset();
    //a2->setId(Tools::idGenerator());
    a2->setName("martillos");
    a2->setDescription("martillos para madera");
    a2->setRentTime(10);
    elian_estrada->getAssets()->insert(Tools::idGenerator(),a2);

    Asset *a3 = new Asset();
    //a3->setId(Tools::idGenerator());
    a3->setName("caladora");
    a3->setDescription("caladora para cortar maderas prefabricadas");
    a3->setRentTime(15);
    elian_estrada->getAssets()->insert(Tools::idGenerator(),a3);

    Asset *a4 = new Asset();
    //a4->setId(Tools::idGenerator());
    a4->setName("barreno");
    a4->setDescription("barreno para concreto");
    a4->setRentTime(5);
    elian_estrada->getAssets()->insert(Tools::idGenerator(),a4);
//////////
    User *juanito = new User();
    juanito->setFullName("Juan Perez");
    juanito->setPassword("4567");
    matrix->insertUser(juanito, "juanito", "jutiapa", "max");

/////////
    User *pedrito = new User();
    pedrito->setFullName("Pedro Rodriguez");
    pedrito->setPassword("48956");
    matrix->insertUser(pedrito, "pedrito", "jalapa", "usac");
//////////////
    User *mafer = new User();
    mafer->setFullName("Maria Fernanda");
    mafer->setPassword("54312");
    matrix->insertUser(mafer, "mafer", "peten", "cinepolis");
////////////
    User *juanma = new User();
    juanma->setFullName("Juan Manuel");
    juanma->setPassword("32897");
    matrix->insertUser(juanma, "juanma", "guatemala", "usac");
/////////////
    User *casimiro = new User();
    casimiro->setFullName("Carlos Perez");
    casimiro->setPassword("721896");
    matrix->insertUser(casimiro, "casimiro", "guatemala", "max");

    Asset *b1 = new Asset();
    b1->setId(Tools::idGenerator());
    b1->setName("balanza");
    b1->setDescription("balanza con maximo de 25kg");
    b1->setRentTime(15);
    casimiro->getAssets()->insert(b1->getId(),b1);

    Asset *b2 = new Asset();
    b2->setId(Tools::idGenerator());
    b2->setName("canastas");
    b2->setDescription("canastas para frutas y verduras");
    b2->setRentTime(45);
    casimiro->getAssets()->insert(b2->getId(),b2);

    Asset *b3 = new Asset();
    b3->setId(Tools::idGenerator());
    b3->setName("linternas");
    b3->setDescription("linternas para alumbrar cuartos oscuros");
    b3->setRentTime(10);
    casimiro->getAssets()->insert(b3->getId(),b3);

    Asset *b4 = new Asset();
    b4->setId(Tools::idGenerator());
    b4->setName("cargadores");
    b4->setDescription("cargadores de telefonos tipo c");
    b4->setRentTime(5);
    casimiro->getAssets()->insert(b4->getId(),b4);

    Asset *b5 = new Asset();
    b5->setId(Tools::idGenerator());
    b5->setName("cables");
    b5->setDescription("cables de todo tipo");
    b5->setRentTime(10);
    casimiro->getAssets()->insert(b5->getId(),b5);

    Asset *b6 = new Asset();
    b6->setId(Tools::idGenerator());
    b6->setName("lazos");
    b6->setDescription("lazos para tender ropa");
    b6->setRentTime(20);
    casimiro->getAssets()->insert(b6->getId(),b6);
////////////
    User *fuego03 = new User();
    fuego03->setFullName("Fernando Mendez");
    fuego03->setPassword("891346");
    matrix->insertUser(fuego03, "fuego03", "jutiapa", "cinepolis");

    Asset *c1 = new Asset();
    c1->setId(Tools::idGenerator());
    c1->setName("termos");
    c1->setDescription("pequeños termos para bebidas calientes");
    c1->setRentTime(10);
    fuego03->getAssets()->insert(c1->getId(),c1);

    Asset *c2 = new Asset();
    c2->setId(Tools::idGenerator());
    c2->setName("maletas");
    c2->setDescription("maletas desde pequeñas a grandes");
    c2->setRentTime(15);
    fuego03->getAssets()->insert(c2->getId(),c2);

    Asset *c3 = new Asset();
    c3->setId(Tools::idGenerator());
    c3->setName("peliculas");
    c3->setDescription("todo tipo de peliculas de accion");
    c3->setRentTime(5);
    fuego03->getAssets()->insert(c3->getId(),c3);
///////////
    User *azurdia = new User();
    azurdia->setFullName("Alejandra Guzman");
    azurdia->setPassword("780145");
    matrix->insertUser(azurdia, "azurdia", "jutiapa", "usac");
////////////////
    User *incrediboy = new User();
    incrediboy->setFullName("Iraldo Martinez");
    incrediboy->setPassword("201598");
    matrix->insertUser(incrediboy, "incrediboy", "jutiapa", "max");

    Asset *d1 = new Asset();
    d1->setId(Tools::idGenerator());
    d1->setName("casest");
    d1->setDescription("casets con musica de todo tipo");
    d1->setRentTime(5);
    incrediboy->getAssets()->insert(d1->getId(),d1);

    Asset *d2 = new Asset();
    d2->setId(Tools::idGenerator());
    d2->setName("pantallas");
    d2->setDescription("pantallas para proyección");
    d2->setRentTime(10);
    incrediboy->getAssets()->insert(d2->getId(),d2);

    Asset *d3 = new Asset();
    d3->setId(Tools::idGenerator());
    d3->setName("cañonera");
    d3->setDescription("cañonera para proyeccion");
    d3->setRentTime(10);
    incrediboy->getAssets()->insert(d3->getId(),d3);

    Asset *d4 = new Asset();
    d4->setId(Tools::idGenerator());
    d4->setName("toldo");
    d4->setDescription("toldo para eventos al exterior");
    d4->setRentTime(5);
    incrediboy->getAssets()->insert(d4->getId(),d4);
///////////
    User *alcachofa = new User();
    alcachofa->setFullName("Antonio Lopez");
    alcachofa->setPassword("20435");
    matrix->insertUser(alcachofa, "alcachofa", "jalapa", "usac");

    Asset *e1 = new Asset();
    e1->setId(Tools::idGenerator());
    e1->setName("audifonos");
    e1->setDescription("audifonos para grabaciones de estudio");
    e1->setRentTime(10);
    alcachofa->getAssets()->insert(e1->getId(),e1);

    Asset *e2 = new Asset();
    e2->setId(Tools::idGenerator());
    e2->setName("microfonos");
    e2->setDescription("microfonos de todo tipo");
    e2->setRentTime(8);
    alcachofa->getAssets()->insert(e2->getId(),e2);

    Asset *e3 = new Asset();
    e3->setId(Tools::idGenerator());
    e3->setName("pedestales");
    e3->setDescription("pedestales para microfonos grandes y pequeños");
    e3->setRentTime(12);
    alcachofa->getAssets()->insert(e3->getId(),e3);

    Asset *e4 = new Asset();
    e4->setId(Tools::idGenerator());
    e4->setName("atriles");
    e4->setDescription("atriles para colocar ojas con gancho");
    e4->setRentTime(14);
    alcachofa->getAssets()->insert(e4->getId(),e4);
}

