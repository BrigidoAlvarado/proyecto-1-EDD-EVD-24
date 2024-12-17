//
// Created by brigidoalvarado on 15/12/24.
//
#include "../../includes/adminReports/SparseMatrixReportGenerator.h"

#include <complex.h>

#include "../../includes/Tools.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using std::endl;
using std::cout;

const string SparseMatrixReportGenerator::FILE_NAME = "reporte_matriz_dispersa.dot";
const string SparseMatrixReportGenerator::IMAGE_NAME = "reporte_matriz_dispersa.png";

SparseMatrixReportGenerator::SparseMatrixReportGenerator(SparseMatrix *&sparseMatrix)
{
    this->sparseMatrix = sparseMatrix;
}

void SparseMatrixReportGenerator::generateReport()
{
    ofstream file (FILE_NAME);

    if (!file.is_open())
    {
        std::cerr << "  Error al abrir el archivo: " << FILE_NAME << endl;
        Tools::pressStart(false);
        return;
    }

    file << "digraph SparseMatrix {" << endl;
    file << "node [shape=box];" << endl;

    MatrixNode *hAux = sparseMatrix->getHHeader();
    MatrixNode *vAux = sparseMatrix->getVHeader();

    //Generar conecciones con las cabeceras horizontales (los departamentos)
    file << "    // Cabeceras Horizontales" << endl;
    file << "    \"" << "reporte" << "\" -> \"" << hAux->getKey() << "\";" << endl;
    while (hAux != nullptr)
    {
        if (hAux->getnext() != nullptr)
        {
            file << "    \"" << hAux->getKey() << "\" -> \"" << hAux->getnext()->getKey() << "\";" << endl;
            file << "    \"" << hAux->getnext()->getKey() << "\" -> \"" << hAux->getKey() << "\";" << endl;
        }
        hAux = hAux->getnext();
    }

    //Conecciones entre filas
    file << "    // Coneccion entre filas" << endl;

    while (vAux != nullptr)
    {
        MatrixNode *row = vAux;
        while (row->getnext() != nullptr)
        {
            file << "    \"" <<row->getKey() << "\"" << " -> " << row->getnext()->getKey() << ";" << endl;
            file << "    \"" <<row->getnext()->getKey() << "\"" << " -> " << row->getKey() << ";" << endl;
            row = row->getnext();
        }
        vAux = vAux->getdown();
    }

    //Generar conecciones con las cabeceras verticales (las companias)
    file << "    // Cabeceras Verticales" << endl;
    vAux = sparseMatrix->getVHeader();
    file << "    \"" << "reporte" << "\" -> \"" << vAux->getKey() << "\";" << endl;
    while (vAux != nullptr)
    {
        if (vAux->getdown() != nullptr)
        {
            file << "    \"" << vAux->getKey() << "\" -> \"" << vAux->getdown()->getKey() << "\";" << endl;
            file << "    \"" << vAux->getdown()->getKey() << "\" -> \"" << vAux->getKey() << "\";" << endl;
        }
        vAux = vAux->getdown();
    }

    //Conecciones entre Columnas
    file << "    // Coneccion entre filas" << endl;
    hAux = sparseMatrix->getHHeader();
    while (hAux != nullptr)
    {
        MatrixNode *column = hAux;
        while (column->getdown() != nullptr)
        {
            file << "    \"" <<column->getKey() << "\"" << " -> " << column->getdown()->getKey() << ";" << endl;
            file << "    \"" <<column->getdown()->getKey() << "\"" << " -> " << column->getKey() << ";" << endl;
            column = column->getdown();
        }
        hAux = hAux->getnext();
    }

    //Encuadre horizontal
    //Departamentos
    file << "    // Encuadre" << endl;
    hAux = sparseMatrix->getHHeader();
    file << "    { rank=same; reporte; ";
    while (hAux != nullptr)
    {
        file << hAux->getKey() << "; ";
        hAux = hAux->getnext();
    }
    file << "}" << endl;

    //filas
    vAux = sparseMatrix->getVHeader();
    while (vAux != nullptr)
    {
        MatrixNode *row = vAux;
        file << "    { rank=same; ";
        while (row != nullptr)
        {
            file << row->getKey() << "; ";
            row = row->getnext();
        }
        file << "}" << endl;
        vAux = vAux->getdown();
    }

    file << "}" << endl;
    file.close();

    string command = "dot -Tpng " + FILE_NAME + " -o " + IMAGE_NAME;
    int result = system(command.c_str());

    std::cout << std::endl;
    if (result == 0) {
        std::cout << "  Imagen '" << IMAGE_NAME << "' generada correctamente.\n";
    } else {
        std::cerr << "  Error al generar la imagen '" << IMAGE_NAME << "\n";
    }
    Tools::pressStart(true);
}