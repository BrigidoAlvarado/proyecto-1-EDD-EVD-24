//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/Admin.h"
#include "../includes/User.h"
#include "../includes/Tools.h"
#include <iostream>

#include "../includes/AdminMenu.h"
#include "../includes/adminReports/SparseMatrixReportGenerator.h"
using namespace std;

Admin::Admin()
{
    this->sparseMatrix = new SparseMatrix();
}

Admin::Admin(SparseMatrix* sparseMatrix)
{
    this->sparseMatrix = sparseMatrix;
}

void Admin::enterUser()
{
    cin.clear();
    cin.ignore();
    cout << endl;
    cout << "%%%%%%%%%%%%%%%%% Ingresar Nuevo Usuario %%%%%%%%%%%%%%%%%" << endl;
    string name;
    cout << " -> Nombre: ";
    getline(cin, name);
    string password;
    cout << " -> Contraseña: ";
    getline(cin, password);
    string fullName;
    cout << " -> Nombre Completo: ";
    getline(cin, fullName);
    string department;
    cout << " -> Departamento: ";
    getline(cin, department);
    string company;
    cout << " -> Compania: ";
    getline(cin, company);

    //se crea un objeto de tipo usuario
    User *user = new User();
    user->setPassword(password);
    user->setFullName(fullName);

    //se inserta el nuevo usuario
    sparseMatrix->insertUser(user, name, department, company);
    cout << endl;
    cout << "  Usuario ingresado exitosamente" << endl;
    cout << "matriz dispersa es: " << sparseMatrix << endl;
    cout << "cabecera es: " << sparseMatrix->getHHeader()->getKey() << " " << sparseMatrix->getVHeader()->getKey() << endl;
    Tools::pressStart(false);
}

void Admin::generateSparseMatrixReport()
{
    cout << "matriz dispersa es: " << sparseMatrix << endl;
    cout << "cabecera es: " << sparseMatrix->getHHeader() << " " << sparseMatrix->getVHeader() << endl;
    SparseMatrixReportGenerator sparseMatrixReportGenerator = SparseMatrixReportGenerator(sparseMatrix);
    sparseMatrixReportGenerator.generateReport();
}
