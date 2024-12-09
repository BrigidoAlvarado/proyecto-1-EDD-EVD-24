//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef MATRIXNODE_H
#define MATRIXNODE_H
#include <string>
#include"../User.h"

using std:: string;

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
    string name;

    public:
    MatrixNode()
    {
        next = NULL;
        prev = NULL;
        up = NULL;
        down = NULL;
        forward = NULL;
        backward = NULL;
        user = NULL;
    };

    ~MatrixNode();
// setters
    void setnext(MatrixNode *next);
    void setprev(MatrixNode *prev);

    void setup(MatrixNode *up);
    void setDown(MatrixNode *down);

    void setForward(MatrixNode *forward);
    void setBackward(MatrixNode *backward);

    void setUser(User *user);
    void setName(string name);

//  getters
    MatrixNode *getnext();
    MatrixNode *getprev();

    MatrixNode *getup();
    MatrixNode *getdown();

    MatrixNode *getforward();
    MatrixNode *getbackward();

    User *getuser();
    string getname();
};
#endif //MATRIXNODE_H
