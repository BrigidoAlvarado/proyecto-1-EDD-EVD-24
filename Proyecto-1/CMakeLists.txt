cmake_minimum_required(VERSION 3.30)
project(Proyecto_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto_1 main.cpp
        includes/Login.h
        src/Login.cpp
        includes/SystemMemory.h
        src/SystemMemory.cpp
        includes/admin/Admin.h
        src/admin/Admin.cpp
        includes/admin/AdminMenu.h
        src/admin/AdminMenu.cpp)
