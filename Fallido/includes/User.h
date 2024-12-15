//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef USER_H
#define USER_H
#include <string>

#include "SystemMemory.h"
#include "avlTree/AvlTree.h"

using std:: string;
class User
{
private:
    string name;
    string password;
    string fullName;

    AvlTree *assets;

    public:
    User()
    {
        name = "";
        password = "";
        fullName = "";
        assets = new AvlTree();
    };
    //setters
    void setName(string name);
    void setPassword(string password);
    void setFullName(string fullName);
    //getters
    string getName();
    string getPassword();
    string getFullName();
    AvlTree *getAvlTree();
};

#endif //USER_H
