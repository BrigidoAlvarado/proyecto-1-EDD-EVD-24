//
// Created by brigidoalvarado on 16/12/24.
//
#include "../includes/Asset.h"

Asset::Asset()
{
    this->name = "";
    this->description = "";
    this->id = "";
    this->rentTime = 0;
    this->rented = false;
}

void Asset::setName( string name)
{
    this->name = name;
}

void Asset::setDescription(string description)
{
    this->description = description;
}

string Asset::getName()
{
    return this->name;
}

string Asset::getDescription()
{
    return this->description;
}

void Asset::setId(string id)
{
    this->id = id;
}

string Asset::getId()
{
    return this->id;
}

void Asset::setRented(bool rented)
{
    this->rented = rented;
}

bool Asset::getRented()
{
    return this->rented;
}

void Asset::setRentTime(int rentTime)
{
    this->rentTime = rentTime;
}

int Asset::getRentTime()
{
    return this->rentTime;
}