//
// Created by brigidoalvarado on 16/12/24.
//
#include "../../includes/avlTree/AvlNode.h"

AvlNode::AvlNode(string id)
{
    this->id = id;
    this->left = nullptr;
    this->right = nullptr;
    this->balanceFactor = 0;
}

void AvlNode::setValue(string id, Asset* asset)
{
    this->id = id;
    this->asset = asset;
}

void AvlNode::setAsset(Asset* asset)
{
    this->asset = asset;
}

void AvlNode::setLeft(AvlNode* node)
{
    this->left = node;
}

void AvlNode::setRight(AvlNode* node)
{
    this->right = node;
}

void AvlNode::setBalanceFactor(int balanceFactor)
{
    this->balanceFactor = balanceFactor;
}

int AvlNode::getBalanceFactor()
{
    return this->balanceFactor;
}


string AvlNode::getId()
{
    return this->id;
}

AvlNode* &AvlNode::getLeft()
{
    return this->left;
}

AvlNode* &AvlNode::getRight()
{
    return this->right;
}

Asset*& AvlNode::getAsset()
{
    return this->asset;
}
