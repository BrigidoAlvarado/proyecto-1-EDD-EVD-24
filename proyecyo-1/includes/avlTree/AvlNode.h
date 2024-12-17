//
// Created by brigidoalvarado on 16/12/24.
//

#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>
#include "../Asset.h"
using namespace std;

class AvlNode
{
private:
    string id;
    AvlNode *left;
    AvlNode *right;
    Asset *asset;
    int balanceFactor;

public:
    AvlNode(string id);
    //setters
    void setBalanceFactor(int balanceFactor);
    void setLeft(AvlNode *node);
    void setRight(AvlNode *node);
    void setAsset(Asset *asset);
    void setValue(string id, Asset *asset);
    //getters
    string   getId();
    AvlNode *&getLeft();
    AvlNode *&getRight();
    Asset *&getAsset();
    int getBalanceFactor();
};

#endif //AVLNODE_H
