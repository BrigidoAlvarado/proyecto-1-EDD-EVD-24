//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "Admin.h"
class AdminMenu
{
private:
    Admin *admin;
public:
    AdminMenu(Admin *admin);
    void displayMenu();
};
#endif //ADMINMENU_H
