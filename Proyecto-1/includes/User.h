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
    string department;
    string company;

    SystemMemory memory;
    AvlTree assets;

    public:
    User(SystemMemory memory);
    //setters
    void setName(string name);
    void setPassword(string password);
    void setFullName(string fullName);
    void setDepartment(string department);
    void setCompany(string company);
    void setAvlTree(AvlTree avlTree);
    //getters
    string getName();
    string getPassword();
    string getFullName();
    string getDepartment();
    string getCompany();
    SystemMemory getMemory();
    AvlTree getAvlTree();
};

#endif //USER_H
