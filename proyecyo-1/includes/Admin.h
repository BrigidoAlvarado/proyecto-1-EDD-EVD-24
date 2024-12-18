//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "sparseMatrix/SparseMatrix.h"

class Admin
{
private:
    SparseMatrix *sparseMatrix;
public:
    Admin();
    Admin(SparseMatrix *sparseMatrix);
    void enterUser();
    void generateSparseMatrixReport();
    void generateAvlUserReport();
    SparseMatrix *getSparseMatrix();
};
#endif //ADMIN_H
