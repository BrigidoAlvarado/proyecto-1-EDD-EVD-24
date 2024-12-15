//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/User.h"

User::User()
{
    this->name = "";
    this->fullName = "";
    this->password = "";
}

void User::setName(string name)
{
    this->name = name;
}

string User::getName()
{
    return this->name;
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