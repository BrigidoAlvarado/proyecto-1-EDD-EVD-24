#include <iostream>

#include "includes/Admin.h"
#include "includes/User.h"
#include "includes/PrincipalMenu.h"
#include "includes/adminReports/SparseMatrixReportGenerator.h"

int main()
{
    PrincipalMenu menu = PrincipalMenu();
    menu.displayMenu();
    /*User *user = new User();
    user->setPassword("123");
    SparseMatrix *matrix = new SparseMatrix();
    matrix->insertUser(user, "Josias", "Guatemala", "Cinepolis");
    matrix->insertUser(user, "Ronald", "Totonicapan", "Max");
    matrix->insertUser(user, "Bernardo", "Juatiapa", "CocaCola");
    matrix->insertUser( user, "Juan", "Guatemala", "CocaCola");
    matrix->insertUser( user, "Geronima", "Jutiapa", "Max");
    matrix->insertUser(user, "Brigido", "Guatemala", "Max");
    matrix->insertUser(user, "Rogelio", "Guatemala", "Max");

    SparseMatrixReportGenerator *reportGenerator = new SparseMatrixReportGenerator(matrix);
    reportGenerator->generateReport();

    User *user1 = matrix->getUser("Rogelio","123", "Guatemala", "Max");*/

    return 0;
}