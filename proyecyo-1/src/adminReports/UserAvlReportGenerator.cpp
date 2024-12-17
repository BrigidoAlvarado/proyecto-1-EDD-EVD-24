//
// Created by brigidoalvarado on 17/12/24.
//
#include "../../includes/adminReports/UserAvlReportGenerartor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../../includes/Tools.h"

using std::endl;
using std::cout;

const string UserAvlReportGenerartor::FILE_NAME = "user_avl_report.dot";
const string UserAvlReportGenerartor::IMAGE_NAME = "user_avl_report.png";

void UserAvlReportGenerartor::genetateReport(AvlTree* tree)
{
    std:ofstream file(FILE_NAME);
    if (!file.is_open())
    {
        cerr << "  Error al crear el archivo DOT: " << FILE_NAME << endl;
        return;
    }

    file << "digraph userAvlTree {" << endl;
    file << "node [shape=circle, style=filled, color=lightblue];" << endl;

    generateDotContent(file, tree->getRoot());

    file << "}" << endl;
    file.close();

    string command = "dot -Tpng " + FILE_NAME + " -o " + IMAGE_NAME;
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << " Imagen PNG generada: " << IMAGE_NAME << std::endl;
    } else {
        std::cerr << " Error al generar la imagen PNG." << std::endl;
    }
    Tools::pressStart(true);
}

void UserAvlReportGenerartor::generateDotContent(std::ofstream& file, AvlNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    // Escribir el nodo actual
    file << "    \"" << node->getId() << "\" [label=\"" << node->getId()
         << "\\nNombre: " << node->getAsset()->getName() << "\"];" << std::endl;

    // Conectar con el nodo izquierdo
    if (node->getLeft() != nullptr) {
        file << "    \"" << node->getId() << "\" -> \"" << node->getLeft()->getId() << "\";" << std::endl;
        generateDotContent(file, node->getLeft());
    }

    // Conectar con el nodo derecho
    if (node->getRight() != nullptr) {
        file << "    \"" << node->getId() << "\" -> \"" << node->getRight()->getId() << "\";" << std::endl;
        generateDotContent(file, node->getRight());
    }
}