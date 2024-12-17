cmake_minimum_required(VERSION 3.30)
project(proyecyo_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(proyecyo_1 main.cpp
        includes/PrincipalMenu.h
        src/PrinicipalMenu.cpp
        includes/AdminMenu.h
        includes/Admin.h
        src/AdminMenu.cpp
        src/Admin.cpp
        includes/User.h
        src/User.cpp
        includes/sparseMatrix/MatrixNode.h
        src/sparseMatrix/MatrixNode.cpp
        includes/sparseMatrix/SparseMatrix.h
        src/sparseMatrix/SparseMatrix.cpp
        includes/Tools.h
        src/Tools.cpp
        includes/adminReports/SparseMatrixReportGenerator.h
        src/adminReports/SparseMatrixReportGenerator.cpp
        includes/UserMenu.h
        src/UserMenu.cpp
        src/avlTree/AvlNode.cpp
        includes/avlTree/AvlTree.h
        includes/avlTree/AvlNode.h
        src/avlTree/AvlTree.cpp
        includes/Asset.h
        src/Asset.cpp
        includes/adminReports/UserAvlReportGenerartor.h
        src/adminReports/UserAvlReportGenerator.cpp)
