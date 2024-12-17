//
// Created by brigidoalvarado on 16/12/24.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#include "AvlNode.h"
#include "../Asset.h"

class AvlTree
{
private:
    AvlNode *root;
    //devuelve al altura maxima
    int maxHeight(AvlNode *node);
    //devuelve el factor de equilibrio
    int calcBalanceFactor(AvlNode *node);
    //se inserta un nuevo valor al arbol
    void insert(AvlNode *value , AvlNode* &root);
    //ROTACIONES
    //Rotacion simple a la izquierda
    void turnRight(AvlNode *& node);
    //Rotacion doble izquierda derecha
    void turnRightLeft(AvlNode *& node);
    //Rotacion simple a la derecha
    void turnLeft(AvlNode *& node);
    //Rotacion doble derecha izquierda
    void turnLeftRight( AvlNode *& node);
    //elimina un activo
    void deleteAsset(string id, AvlNode *& root);
    //
    AvlNode *furtherRight(AvlNode *& node);
    //
    bool isLeaf(AvlNode *node);
    //
    void printTree(AvlNode *root);
    //
    Asset *getAsset(string id, AvlNode *& root);
public:
    AvlTree();
    //setters
    void setRoot(AvlNode *root);
    //getters
    AvlNode *getRoot();
    //inserta un nuevo valor al arbol
    void insert(string id, Asset *asset);
    //elimina un activo
    void deleteAsset(string id);
    //
    void printTree();

    Asset *getAsset(string id);
};
#endif //AVLTREE_H
