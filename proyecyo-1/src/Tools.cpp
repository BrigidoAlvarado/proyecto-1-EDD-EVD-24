//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/Tools.h"
#include <iostream>
#include <limits>
using namespace std;

void Tools::pressStart()
{
    cout << "Presione Enter par continuar..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}