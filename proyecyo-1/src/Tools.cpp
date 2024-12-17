//
// Created by brigidoalvarado on 15/12/24.
//
#include "../includes/Tools.h"
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <ctime>
using namespace std;

void Tools::pressStart(bool cleanBP)
{
    cout << "  Presione Enter para continuar..." << endl;
    cin.clear();
    if (cleanBP)
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cin.get();
}

string Tools::idGenerator()
{
    const int idLength = 15; // Longitud del ID
    const std::string chars = "abcdefghijklmnopqrstuvwxyz0123456789"; // Letras minúsculas y números
    std::string randomID;

    // Generador de números aleatorios
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr))); // Semilla basada en tiempo
    std::uniform_int_distribution<> dist(0, chars.size() - 1); // Rango de índices

    for (int i = 0; i < idLength; ++i) {
        randomID += chars[dist(rng)];
    }

    return randomID;
}
