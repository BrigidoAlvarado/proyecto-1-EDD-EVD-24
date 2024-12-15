//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef PRINCIPALMENU_H
#define PRINCIPALMENU_H
#include <iostream>
using std::string;

class PrincipalMenu
{
public:
    static const string ADMIN_NAME;
    static const string ADMIN_PASSWORD;

    void displayMenu();
private:
    void displayLoginMenu();
    bool validateAdminCredentials(string name, string password);
};
#endif //PRINCIPALMENU_H
