//
// Created by brigidoalvarado on 8/12/24.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "../SystemMemory.h"

class User;

class Admin
{
private:
    SystemMemory *systemMemory;

public:
    Admin( SystemMemory *systemMemory);
    ~Admin();
    //Acciones (se acceden desde el menu)
    void registerUser();
};
#endif //ADMIN_H
