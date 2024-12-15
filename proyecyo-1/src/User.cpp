//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/User.h"

User::User()
{
    this->fullName = "";
    this->password = "";
}

void User::setFullName(string fullName)
{
    this->fullName = fullName;
}

string User::getFullName()
{
    return this->fullName;
}

void User::setPassword(string password)
{
    this->password = password;
}

string User::getPassword()
{
    return this->password;
}