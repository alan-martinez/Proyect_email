#ifndef CORREO_H
#define CORREO_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Correo
{
    private:
        unsigned long int id;
        char remitente[20];
        char destinatario[50];
        char copiaCarbono[50];
        char copiaCarbonoCiega[20];
        char asunto[50];
        char contenido[200];

        char dia[10];
        char hora[5];
        void funcionDiaHora();
        //const string currentDateTime();
    
    public:
        Correo();

        int getId() const;
        char* getDia() const;
        char* getHora() const;
        char* getRemitente() const;
        char* getDestinatario() const;
        char* getCopiaCarbono() const;
        char* getCopiaCarbonoCiega() const;
        char* getAsunto() const;
        char* getContenido() const;

        void setId(const int &);
        void setRemitente(char* );
        void setDestinatario(char* );
        void setCopiaCarbono(char* );
        void setCopiaCarbonoCiega(char* );
        void setAsunto(char* );
        void setContenido();

};


#endif  