//
// Created by brigidoalvarado on 16/12/24.
//

#ifndef USERMENU_H
#define USERMENU_H
#include "User.h"

class UserMenu
{
private:
    User *user;
    void insertAsset();
    void deleteAsset();

public:
    UserMenu(User *user);
    void displayMenu();
};
#endif //USERMENU_H
