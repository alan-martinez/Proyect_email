#include <fstream>
#include "correo.h"

using namespace std;

class Archivo
{
    private:
        fstream archivo;

        unsigned long apuntador(unsigned long int&);
        char apuntadorCadena(char& );

    public:
        Archivo();

        void escribir(const Correo&,unsigned long int&);
        void leer(unsigned long int&);
        void modificar(unsigned long int&);

        //Implementaciones acividad 3:
        void buscarRemitente( char &);
};