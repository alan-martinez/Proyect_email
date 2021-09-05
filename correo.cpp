#include <iostream>
#include <ctime>
//#include <stdio.h>
#include <cstring>
#include "correo.h"

using namespace std;

Correo::Correo(){}

void Correo::funcionDiaHora(){
    time_t now = time(nullptr);
    struct tm tm = *localtime(&now);
    sprintf(hora, "%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    sprintf(hora, "%d:%d", tm.tm_hour, tm.tm_min);
}

int Correo::getId() const{
    return id;
}


char* Correo::getRemitente() const {
    return (char* )remitente;
}

char* Correo::getDestinatario() const {
    return (char* )destinatario;
}

char* Correo::getCopiaCarbono() const {
    return (char* )copiaCarbono;
}

char* Correo::getCopiaCarbonoCiega() const {
    return (char* )copiaCarbonoCiega;
}

char* Correo::getAsunto() const {
    return (char* )asunto;
}

char* Correo::getContenido() const{
    return (char* ) contenido;
}

char* Correo::getDia() const {
    return (char* )dia;
}

char* Correo::getHora() const {
    return (char* )hora;
}

//setters:
void Correo::setId(const int &i){
    id = i;
}

void Correo::setRemitente(char* r){
    strncpy(remitente, r, 20);
}

void Correo::setDestinatario(char* d){
    strncpy(destinatario, d, 50);
}

void Correo::setCopiaCarbono(char* cc){
    strncpy(copiaCarbono, cc, 50);
}

void Correo::setCopiaCarbonoCiega(char* ccb){
    strncpy(copiaCarbonoCiega, ccb, 20);
}

void Correo::setAsunto(char* a){
    strncpy(asunto, a, 50);
}

void Correo::setContenido(){

    char temp[200], final[200];
    bool bandera = true;

    int i = 0, j, contador = 0;
    int co1, co2;

    do{
        cin.getline(temp, 200);

        while (temp[i] != '\000'){
            i++;
        }

        temp[i] = '\n';

        contador += i+1;

        if (temp[0] == 'E' and temp[i - 1] == 'R'){
            bandera = false;
        }
        else {
            for (j = co1, co2 = 0; j < contador; j++, co2++){
                final[j] = temp[co2];
            }

            co1 = contador;
        }
        i = 0;
    }
    while (bandera);

    //funcionDiaHora();
    strncpy(contenido, final, 200);
    // currentDateTime();
    cout << endl;
}

