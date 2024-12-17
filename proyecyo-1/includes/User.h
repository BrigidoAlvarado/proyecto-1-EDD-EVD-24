//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef USER_H
#define USER_H

#include <iostream>

#include "avlTree/AvlTree.h"
using namespace std;

class User
{
private:
    string fullName;
    string password;
    AvlTree *assets;

    public:
    User();
    //getter and setters
    void setFullName(string fullName);
    string getFullName();
    void setPassword(string password);
    string getPassword();
    AvlTree *getAssets();
};
#endif //USER_H
