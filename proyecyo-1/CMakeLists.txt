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
        src/sparseMatrix/MatrixNode.cpp)
