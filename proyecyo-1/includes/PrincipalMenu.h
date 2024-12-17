//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef PRINCIPALMENU_H
#define PRINCIPALMENU_H
#include <iostream>
#include "../includes/sparseMatrix/SparseMatrix.h"
using std::string;

class PrincipalMenu
{
public:
    static const string ADMIN_NAME;
    static const string ADMIN_PASSWORD;

    PrincipalMenu();
    PrincipalMenu(SparseMatrix *matrix);
    void displayMenu();
    void init();
private:
    SparseMatrix *matrix;
    void displayLoginMenu();
    bool validateAdminCredentials(string name, string password);
};
#endif //PRINCIPALMENU_H
