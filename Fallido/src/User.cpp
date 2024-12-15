//
// Created by brigidoalvarado on 8/12/24.
//
#include "../includes/User.h"
#include "../includes/SystemMemory.h"

User::User()
{
  User::name = nullptr;
}

void User::setName(string name)
{
    this->name = name;
}

void User::setPassword(string password)
{
    this->password = password;
}

void User::setFullName(string fullName)
{
    this->fullName = fullName;
}

string User::getName()
{
    return this->name;
}

string User::getPassword()
{
    return this->password;
}

string User::getFullName()
{
    return this->fullName;
}

SystemMemory* User::getMemory()
{
    return this->memory;
}

AvlTree* User::getAvlTree()
{
    return this->assets;
}