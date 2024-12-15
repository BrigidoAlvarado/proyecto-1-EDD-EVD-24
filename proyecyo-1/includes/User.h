//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
private:
    string name;
    string fullName;
    string password;

    public:
    User();
    //getter and setters
    void setName(string name);
    string getName();
    void setFullName(string fullName);
    string getFullName();
    void setPassword(string password);
    string getPassword();
};
#endif //USER_H
