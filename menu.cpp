#include "menu.h"
//#include "archivo.h"
//#include "correo.h"

#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

Menu::Menu()
{
    opcion = 0;
}

void Menu::eje()
{
    do{
        cout << "1. Escribir correo" << endl;
        cout << "2. Leer correo" << endl;
        cout << "3. Modificar correo" << endl;
        cout << "4. Salir" << endl;

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
    char *puntero;
    char temp[200];
    puntero = temp;
    unsigned long int posicion;
    unsigned long int buscar;

    switch(opcion){
        case 1:
            {
                cout << endl;
                cout << "Datos del nuevo correo" << endl;
                cout << "ID: " << endl;
                cin >> posicion;
                correo.setId(posicion);
                cin.ignore();

                cout << "Remitente: " << endl;
                cin.getline(temp,20);
                correo.setRemitente(puntero);

                cout << "Destinatario: " << endl;
                cin.getline(temp,50);
                correo.setDestinatario(puntero);

                cout << "Copia carbono: " << endl;
                cin.getline(temp,50);
                correo.setCopiaCarbono(puntero);

                cout << "Copia carbono ciega: " << endl;
                cin.getline(temp,20);
                correo.setCopiaCarbonoCiega(puntero);

                cout << "Asunto: " << endl;
                cin.getline(temp,50);
                correo.setAsunto(puntero);

                cout << "Contenido: " << endl;
                cout << "Para enviar escribe -EXIT-" << endl;
                correo.setContenido();
                cout << endl << endl;

                archivo.escribir(correo, posicion);

                break;
            }
        case 2:
            {
                cout << "Ingresa el ID del correo a buscar: " << endl;
                cin >> posicion;
                archivo.leer(posicion);
                break;
            }
        case 3:
            {
                cout << "Ingresa el ID del correo a modificar: " << endl;
                cin >> posicion;
                archivo.modificar(posicion);
                break;
                
            }
        case 4:
            {
                break;
            }
        default:
            break;
    }
}