//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "Admin.h"

#endif //ADMINMENU_H

class AdminMenu
{
    private:
        Admin *admin;

    public:
        AdminMenu(Admin *admin);
        ~AdminMenu();

        void showMenu();
};