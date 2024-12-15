//
// Created by brigidoalvarado on 15/12/24.
//
#include "../../includes/sparseMatrix/MatrixNode.h"

MatrixNode::MatrixNode(string key)
{
    this->key = key;
    this->user = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
    this->forward = nullptr;
    this->backward = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

MatrixNode::MatrixNode(string key, User* user)
{
    this->key = key;
    this->user = user;
    this->next = nullptr;
    this->prev = nullptr;
    this->forward = nullptr;
    this->backward = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

void MatrixNode::setnext(MatrixNode* next)
{
    this->next = next;
}

void MatrixNode::setprev(MatrixNode* prev)
{
    this->prev = prev;
}

void MatrixNode::setup(MatrixNode* up)
{
    this->up = up;
}

void MatrixNode::setDown(MatrixNode* down)
{
    this->down = down;
}

void MatrixNode::setForward(MatrixNode* forward)
{
    this->forward = forward;
}

void MatrixNode::setBackward(MatrixNode* backward)
{
    this->backward = backward;
}

MatrixNode* MatrixNode::getnext()
{
    return this->next;
}

MatrixNode* MatrixNode::getprev()
{
    return this->prev;
}

MatrixNode* MatrixNode::getup()
{
    return this->up;
}

MatrixNode* MatrixNode::getdown()
{
    return this->down;
}

MatrixNode* MatrixNode::getforward()
{
    return this->forward;
}

MatrixNode* MatrixNode::getbackward()
{
    return this->backward;
}

string MatrixNode::getKey()
{
    return this->key;
}

User* MatrixNode::getuser()
{
    return this->user;
}
