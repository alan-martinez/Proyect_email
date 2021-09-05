
#include <iostream>
#include <string>
#include <ctime>
//#include <stdio.h>
#include <cstring>
#include <fstream>

using namespace std;

class Correo
{
    private:
        int id;
        char dia[10];
        char hora[5];
        char remitente[20];
        char destinatario[20];
        char copiaCarbono[10];
        char copiaCarbonoCiega[10];
        char asunto[30];
        char contenido[20];

        void funcionDiaHora();
    
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
        void setRemitente(char*);
        void setDestinatario(char* );
        void setCopiaCarbono(char* );
        void setCopiaCarbonoCiega(char* );
        void setAsunto(char* );
        void setContenido();

        char* toStringBackup() const;
};

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

char* Correo::getDia() const {
    return (char* )dia;
}

char* Correo::getHora() const {
    return (char* )hora;
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

//setters:
void Correo::setId(const int &i){
    id = i;
}

void Correo::setRemitente(char* r){
    strncpy(remitente, r, 20);
}

void Correo::setDestinatario(char* d){
    strncpy(destinatario, d, 20);
}

void Correo::setCopiaCarbono(char* cc){
    strncpy(copiaCarbono, cc, 10);
}

void Correo::setCopiaCarbonoCiega(char* ccb){
    strncpy(copiaCarbono, ccb, 10);
}

void Correo::setAsunto(char* a){
    strncpy(asunto, a, 30);
}

void Correo::setContenido(){

    char temp[200], final[200];
    bool bandera = true;

    int i = 0, j, counter = 0, k, a;

    do{
        cin.getline(temp, 200);

        while (temp[i] != '\000'){
            i++;
        }

        temp[i] = '\n';

        counter += i+1;

        if (temp[0] == 'E' and temp[i - 1] == 'R'){
            bandera = false;
        }
        else {
            for (j = k, a = 0; j < counter; j++, a++){
                final[j] = temp[a];
            }

            k = counter;
        }
        i = 0;
    }
    while (bandera);

    strncpy(contenido, final, 20);
    funcionDiaHora();
}

char* Correo::toStringBackup() const{
    return nullptr;
}


class Archivo
{
    private:
        fstream archivo;

        unsigned long apuntador(unsigned long int&);

    public:
        Archivo();

        void escribir(const Correo&,unsigned long int&);
};

Archivo::Archivo(){
    
}

unsigned long int Archivo::apuntador(unsigned long int& i){
    return (i-1) * sizeof(Correo);
}

void Archivo::escribir(const Correo& c,unsigned long int& i)
{
    archivo.open("emails.dat", ios::in | ios::out | ios::binary);
    if (archivo.fail()){
        cout << "Ocurrio un error en el archivo" << endl;
        exit(1);
    }
    else {
        archivo.seekp(apuntador(i));
        archivo.write((char*)&c, sizeof(c));
        archivo.close();
        cout << "Registro exitoso" << endl;
    }
}


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

Menu::Menu()
{
    opcion = 0;
}

void Menu::eje()
{
    do{
        cout << "1. Escribir correo" << endl;
        cout << "2. Leer correo" << endl;
        cout << "3. Salir" << endl;

        cout << "Ingrese su opcion: " << endl;
        cin >> opcion;
        menuOpciones();
        cout << endl;
    }
    while (opcion != 4);

    cout << "Saliste!" << endl;
}

void Menu::menuOpciones()
{
    char *cp;
    char miChar[200];
    cp = miChar;
    unsigned long int posicion;

    switch(opcion){
        case 1:
            {
                cout << sizeof(correo) << endl;

                cout << endl;
                cout << "Datos del nuevo correo" << endl;
                cout << "ID: " << endl;
                cin >> posicion;
                correo.setId(posicion);
                cin.ignore();

                cout << "Remitente: " << endl;
                cin.getline(miChar,20);
                correo.setRemitente(cp);

                cout << "Destinatario: " << endl;
                cin.getline(miChar,20);
                correo.setDestinatario(cp);

                cout << "Copia carbono: " << endl;
                cin.getline(miChar,10);
                correo.setCopiaCarbono(cp);

                cout << "Copia carbono ciega: " << endl;
                cin.getline(miChar,10);
                correo.setCopiaCarbonoCiega(cp);

                cout << "Asunto: " << endl;
                cin.getline(miChar,10);
                correo.setAsunto(cp);

                cout << "Contenido:" << endl;
                correo.setContenido();
                cout << endl << endl;

                archivo.escribir(correo, posicion);

                break;
            }
    }
}