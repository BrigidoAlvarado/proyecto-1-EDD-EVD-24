//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef MATRIXNODE_H
#define MATRIXNODE_H

#include <iostream>
#include "../User.h"
using namespace std;

class MatrixNode
{
private:
    MatrixNode *next;
    MatrixNode *prev;

    MatrixNode *up;
    MatrixNode *down;

    MatrixNode *forward;
    MatrixNode *backward;

    User *user;
    string key;

public:
    MatrixNode( string key);
    MatrixNode( string key, User *user);

    // setters
    void setnext(MatrixNode *next);
    void setprev(MatrixNode *prev);

    void setup(MatrixNode *up);
    void setDown(MatrixNode *down);

    void setForward(MatrixNode *forward);
    void setBackward(MatrixNode *backward);

    void setUser(User *user);
    void setKey(string key);

    //  getters
    MatrixNode *getnext();
    MatrixNode *getprev();

    MatrixNode *getup();
    MatrixNode *getdown();

    MatrixNode *getforward();
    MatrixNode *getbackward();

    User *getuser();
    string getKey();
};
#endif //MATRIXNODE_H