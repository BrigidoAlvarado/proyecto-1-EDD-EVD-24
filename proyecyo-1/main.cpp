#include <iostream>

#include "includes/Admin.h"
#include "includes/User.h"
#include "includes/PrincipalMenu.h"
#include "includes/adminReports/SparseMatrixReportGenerator.h"

int main()
{
    //PrincipalMenu menu = PrincipalMenu();
    //menu.displayMenu();
    User *user = new User();
    SparseMatrix *matrix = new SparseMatrix();
    matrix->insertUser(user, "Brigido", "Guatemala", "Max");
    matrix->insertUser(user, "Josias", "Guatemala", "Cinepolis");
    matrix->insertUser(user, "Ronald", "Totonicapan", "Max");
    matrix->insertUser(user, "Bernardo", "Juatiapa", "CocaCola");

    SparseMatrixReportGenerator *reportGenerator = new SparseMatrixReportGenerator(matrix);
    reportGenerator->generateReport();

    return 0;
}
