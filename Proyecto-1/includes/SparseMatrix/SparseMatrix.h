//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "MatrixNode.h"

using std:: string;

class SparseMatrix
{
private:
    MatrixNode *hHeader;
    MatrixNode *vHeader;

public:
    SparseMatrix();
    ~SparseMatrix();
    //busca una cabezera horizontal con el nombre del departamento ingresado
    MatrixNode *searchHHeader(string department);
    //busca una cabezera vertical con el nombre de la compania ingresado
    MatrixNode *searchVHeader(string company);
    // inserta un usuario
    void insert(User *user);
    MatrixNode *insertHHeader(string department);
    MatrixNode *insertVHeader(string company);
    //valida si la matriz es vacia
    bool isEmpty();
};

#endif //SPARSEMATRIX_H
