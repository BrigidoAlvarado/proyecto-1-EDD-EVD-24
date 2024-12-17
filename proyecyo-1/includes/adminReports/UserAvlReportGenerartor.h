//
// Created by brigidoalvarado on 17/12/24.
//

#ifndef USERAVLREPORTGENERARTOR_H
#define USERAVLREPORTGENERARTOR_H

#include <string>
#include <fstream>
#include "../avlTree/AvlTree.h"
using namespace std;

using std::endl;
using std::cout;

class UserAvlReportGenerartor
{
public:
    const static string FILE_NAME;
    const static string IMAGE_NAME;
    void genetateReport(AvlTree *tree);
private:
    void generateDotContent(std::ofstream &file, AvlNode *node);
};
#endif //USERAVLREPORTGENERARTOR_H
