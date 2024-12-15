//
// Created by brigidoalvarado on 8/12/24.
//
#include "../../includes/SparseMatrix/MatrixNode.h"
#include "../../includes/User.h"

MatrixNode::MatrixNode(string value)
{
    this->name = value;
}

MatrixNode::MatrixNode(User *user)
{
    this->name = user->getName();
    this->user = user;
}

MatrixNode::~MatrixNode()
{
    delete this;
}

//SETTERS
void MatrixNode::setnext(MatrixNode* next)
{
    this->next = next;
}

void MatrixNode::setprev(MatrixNode* prev)
{
    this->prev = prev;
}

void MatrixNode::setup(MatrixNode *up)
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

void MatrixNode::setUser(User* user)
{
    this->user = user;
}
void MatrixNode::setName(string name)
{
    this->name = name;
}

//GETTERS
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

User* MatrixNode::getuser()
{
    return this->user;
}

string MatrixNode::getname()
{
    return this->name;
}