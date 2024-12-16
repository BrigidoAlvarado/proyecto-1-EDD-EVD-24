//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "MatrixNode.h"
#include "../User.h"

using std:: string;

class MatrixNode;
class SparseMatrix
{
private:
    MatrixNode *hHeader;
    MatrixNode *vHeader;

    //busca una cabezera horizontal con el nombre del departamento ingresado
    MatrixNode *searchHHeader(string department);
    //busca una cabezera vertical con el nombre de la compania ingresado
    MatrixNode *searchVHeader(string company);
    //Insersiones
    void insertAtTheEnd(User *&user, MatrixNode *hHeader, MatrixNode *vHeader);
    //inserta una nueva cabecera con el nombre del departamento

    MatrixNode *insertHHeader(string department);
    MatrixNode *insertVHeader(string company);
    //valida si la matriz es vacia
    bool isEmpty();

public:
    SparseMatrix();
    ~SparseMatrix();

    // inserta un usuario
    void insert(User *user, string department, string company);

};
#endif //SPARSEMATRIX_H