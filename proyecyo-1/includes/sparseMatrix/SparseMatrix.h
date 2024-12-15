//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "MatrixNode.h"

class SparseMatrix
{
private:
    MatrixNode *hHeader;
    MatrixNode *vHeader;

    //busca una cabezera horizontal con el nombre del departamento ingresado
    MatrixNode *searchDeparment(string department);
    //busca una cabezera vertical con el nombre de la compania ingresado
    MatrixNode *searchCompany(string company);
    //Insersiones
    void insertAtTheEnd(User *&user, MatrixNode *department, MatrixNode *company, string key);
    //Inserta una nueva cabecera horizontal con el nombre del departamento del parametro
    MatrixNode *insertHHeader(string department);
    //Inserta una nueva cabecera vertical con el nombre de la compania del parametro
    MatrixNode *insertVHeader(string company);
    //valida si la matriz es vacia
    bool isEmpty();

public:
    SparseMatrix();
    void insertUser(User *&user, string key, string department, string company);
};
#endif //SPARSEMATRIX_H
