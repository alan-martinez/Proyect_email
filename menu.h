#ifndef MENU_H
#define MENU_H

#include "archivo.h"

class Menu{
    private:
        int opcion;
        Archivo archivo;
        Correo correo;

        void menuOpciones();
    public:
        Menu();
        void eje();
};

#endif