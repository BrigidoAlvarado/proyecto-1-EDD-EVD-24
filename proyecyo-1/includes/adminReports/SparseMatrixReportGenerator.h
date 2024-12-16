//
// Created by brigidoalvarado on 15/12/24.
//

#ifndef SPARSEMATRIXREPORTGENERATOR_H
#define SPARSEMATRIXREPORTGENERATOR_H
#include "../sparseMatrix/SparseMatrix.h"

class SparseMatrixReportGenerator
{
private:
    SparseMatrix *sparseMatrix;

public:
    static const string FILE_NAME;
    static const string IMAGE_NAME;
    SparseMatrixReportGenerator(SparseMatrix *&sparseMatrix);
    void generateReport();
    void generateMatrixReport();
};
#endif //SPARSEMATRIXREPORTGENERATOR_H
