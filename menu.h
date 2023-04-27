#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <fstream>

#include "receta.h"
#include "listdoble.h"

class Menu{
private:
    void userInterface(ListDoble<Receta>&);

public:
    Menu(ListDoble<Receta>&);
};

#endif // MENU_H_INCLUDED