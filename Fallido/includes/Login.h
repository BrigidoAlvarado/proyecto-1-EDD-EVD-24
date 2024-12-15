//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include "SystemMemory.h"

using std:: string;

class Login
{
public:
    static const string ADMIN_NAME;
    static const string ADMIN_PASSWORD;

private:
    SystemMemory *systemMemory;

public:
    Login();
    Login(SystemMemory *system_memory);
    ~Login();

    SystemMemory getSystemMemory();

    void loginMenu();
    void pricipalMenu();

private:
    void validAdminCredentials(string name, string password);
};
#endif //LOGIN_H

