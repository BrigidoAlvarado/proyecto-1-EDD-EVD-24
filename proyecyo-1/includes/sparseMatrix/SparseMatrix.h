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
    //Busca si existe un usuario con ese nombre en ese departamento y compania
    MatrixNode *search(string key, MatrixNode *department, MatrixNode * company);
    //INSERSIONES
    //Inserta al final de ambas cabeceras
    void insertAtTheEnd(MatrixNode *user, MatrixNode *department, MatrixNode *company);
    //Inserta al final de la cabecera de los departamentos
    void insertAtTheEndOfDepartment(MatrixNode *user, MatrixNode *department);
    //inserta al final de las companias
    void insertAtTheEndOfCompany(MatrixNode *user, MatrixNode *company);
    //inserta un usuario al medio verticalmente
    void insertAtTheHalfV( MatrixNode *user, MatrixNode *vertical);
    //inserta un usuario al medio horizontalmente
    void insertAtTheHalfH( MatrixNode *user, MatrixNode *horizontal);
    //inserta un usuario detras de otro
    void insertBack(MatrixNode *user, MatrixNode *forward);
    //Inserta una nueva cabecera horizontal con el nombre del departamento del parametro
    MatrixNode *insertHHeader(string department);
    //Inserta una nueva cabecera vertical con el nombre de la compania del parametro
    MatrixNode *insertVHeader(string company);
    //Devuelve el departamento del nodo
    MatrixNode *goToDepartment(MatrixNode *node);
    //Devuelve la compania del nodo
    MatrixNode *goToCompany(MatrixNode *node);
    //Devuelve el ultim nodo de atras de una posicion
    MatrixNode *goToBack(MatrixNode *node, string useName);
    //valida si la matriz es vacia
    bool isEmpty();
    //valida si la cabecera que busco esta mas a abajo
    bool below(MatrixNode *company, string key);
    //valida si la cabecera que busco esta mas a la derecha
    bool futherRight(MatrixNode *department, string key);

public:
    SparseMatrix();
    void insertUser(User *&user, string key, string department, string company);
    User *getUser(string name, string password, string department, string company);
    User *getUser(string name, string department, string company);
    MatrixNode *getHHeader();
    MatrixNode *getVHeader();
};
#endif //SPARSEMATRIX_H
