#include "archivo.h"

#include <iostream>

using namespace std;

Archivo::Archivo(){

}

unsigned long int Archivo::apuntador(unsigned long int& i){
    return (i-1) * sizeof(Correo);
}

char Archivo::apuntadorCadena(char& c){
    return (c-1) * sizeof(Correo);
}

void Archivo::escribir(const Correo& c,unsigned long int& i)
{
    archivo.open("emails.dat", ios::in | ios::out | ios::binary);
    if (archivo.fail()){
        cout << "Ocurrio un error en el archivo" << endl;
        exit(1);
    }
    else {
        archivo.seekp(apuntador(i), ios_base::beg);
        archivo.write((char*)&c, sizeof(c));
        archivo.close();
        cout << "Registro exitoso" << endl;
    }
}

void Archivo::leer(unsigned long int& i)
{
    Correo c;
    archivo.open("emails.dat", ios::in | ios::binary);

    if (archivo.fail()){
        cout << "Ocurrio un error al abrir el archivo" << endl;
        exit(1);
    }
    else {
        archivo.seekp(apuntador(i), ios_base::beg);
        archivo.read((char* )&c, sizeof(Correo));
        archivo.close();

        cout << "Correo encontrado!" << endl;
        cout << "ID: " << c.getId() << endl;
        cout << "Remitente: " << c.getRemitente() << endl;
        cout << "Destinatario: " << c.getDestinatario() << endl;
        cout << "Copia carbono: " << c.getCopiaCarbono() << endl;
        cout << "Copia carbono ciega: " << c.getCopiaCarbonoCiega() << endl;
        cout << "Asunto: " << c.getAsunto() << endl;
        cout << "Contenido: " << c.getContenido() << endl;
    }
}

void Archivo::modificar(unsigned long int& i)
{
    int opcion, bandera;
    int find;
    char auxRemitente[20];
    char auxDestinatario[50];
    char auxCopiaCarbono[50];
    char auxCopiaCarbonoCiega[20];
    char auxAsunto[50];

    Correo correo;

    archivo.open("emails.dat", ios::in | ios::binary);
    fstream temp("temporal.dat",ios::out | ios::binary);


    if (!archivo.good()){
        cout << "Error no se encontro el archivo...!" << endl;
        system("PAUSE");
    }
    else {
            archivo.seekp(apuntador(i), ios_base::beg);
            archivo.read((char* )&correo, sizeof(Correo));

            if (i == correo.getId())
            {
                cout << "ID: " << correo.getId() << endl;
                cout << "Remitente: " << correo.getRemitente() << endl;
                cout << "Destinatario: " << correo.getDestinatario() << endl;
                cout << "Copia carbono: " << correo.getCopiaCarbono() << endl;
                cout << "Copia carbono ciega: " << correo.getCopiaCarbonoCiega() << endl;
                cout << "Asunto: " << correo.getAsunto() << endl;
                cout << "Contenido: " << correo.getContenido() << endl;
                cout << "-----------------------------------------" << endl;
                    cout << "\t\tMenu modificar\n";
                cout << "-----------------------------------------" << endl;
                    cout << "1.- Modificar remitente\n";
                    cout << "2.- Modificar destinatario\n";
                    cout << "3.- Modificar copia carbono\n";
                    cout << "4.- Modificar copia carbono ciega\n";
                    cout << "5.- Modificar asunto\n";
                    cout << "6.- Modificar contenido\n";
                    cout << "0.- SALIR\n";
                    cout << "Introduce la opcion: >" << endl;
                    cin >> opcion;
                    switch(opcion)
                    {
                        case 1:{
                                cout << "Este es el remitente: " << correo.getRemitente() << endl;
                                cout << "Nuevo Remitente: " << endl;
                                cin >> auxRemitente;
                                char *cp;
                                cp = auxRemitente;
                                temp << cp;
                                correo.setRemitente(cp);
                                temp.seekp(apuntador(i), ios_base::beg);
                                temp.write((char* )&correo, sizeof(correo));

                                cout << endl;
                                cout << "Contenido cambiado" << endl;
                                break;
                            }
                        case 2:
                                {
                                    cout << "Este es el destinatario: " << correo.getDestinatario() << endl;
                                    cout << "Nuevo destinatario: " << endl;
                                    cin >> auxDestinatario;
                                    char *cp;
                                    cp = auxDestinatario;
                                    temp << cp;
                                    correo.setDestinatario(cp);
                                    temp.seekp(apuntador(i), ios_base::beg);
                                    temp.write((char* )&correo, sizeof(correo));

                                    cout << endl;
                                    cout << "Contenido cambiado con exito!" << endl;
                                    break;
                                }
                            case 3:
                            {
                                cout << "Este es la copia carbono: " << correo.getCopiaCarbono() << endl;
                                cout << "Nueva copia carbono: " << endl;
                                cin >> auxCopiaCarbono;
                                char *cp;
                                cp = auxCopiaCarbono;
                                temp << cp;
                                correo.setCopiaCarbono(cp);
                                temp.seekp(apuntador(i), ios_base::beg);
                                temp.write((char* )&correo, sizeof(correo));

                                cout << endl;
                                cout << "Contenido cambiado con exito!" << endl;
                                break;
                            }
                            case 4:
                            {
                                cout << "Este es la copia carbono ciega: " << correo.getCopiaCarbonoCiega() << endl;
                                cout << "Nueva copia carbono ciega: " << endl;
                                cin >> auxCopiaCarbonoCiega;
                                char *cp;
                                cp = auxCopiaCarbonoCiega;
                                temp << cp;
                                correo.setCopiaCarbonoCiega(cp);
                                temp.seekp(apuntador(i), ios_base::beg);
                                temp.write((char* )&correo, sizeof(correo));

                                cout << endl;
                                cout << "Contenido cambiado con exito!" << endl;
                                break;
                            }
                            case 5:
                            {
                                cout << "Este es el asunto: " << correo.getAsunto() << endl;
                                cout << "Nuevo asunto: " << endl;
                                cin >> auxAsunto;
                                char *cp;
                                cp = auxAsunto;
                                temp << cp;
                                correo.setAsunto(cp);
                                temp.seekp(apuntador(i), ios_base::beg);
                                temp.write((char* )&correo, sizeof(correo));

                                cout << endl;
                                cout << "Contenido cambiado con exito!" << endl;
                                break;
                            }
                            case 6:
                            {
                                cout << "Este es el contenido: " << correo.getContenido() << endl;
                                cout << "Nuevo contenido: " << endl;
                                // cin >> auxAsunto;
                                // char *cp;
                                // cp = auxAsunto;
                                // temp << cp;
                                correo.setContenido();
                                temp.seekp(apuntador(i), ios_base::beg);
                                temp.write((char* )&correo, sizeof(correo));

                                cout << endl;
                                cout << "Contenido cambiado con exito!" << endl;
                                break;
                            }
                            case 0:
                                break;
                            default:
                                system("cls");
                                cout << "Opcion invalida!\n" << "Ingrese una opcion correcta\n";
                                system("PAUSE");
                                system("cls");
                                break;
                }
                bandera = 1;

                if (bandera != 1)
                {
                    cout << "Codigo no encontrado" << endl;
                    system("PAUSE");
                }
        
            archivo.close();
            cout << "Finalizado" << endl;
            temp.close();
            remove("emails.dat");
            rename("temporal.dat","emails.dat");
        }
    }
}

void Archivo::buscarRemitente(char& f)
{
    Correo c;
    char remi[20];
    char *aux;

    archivo.open("emails.dat", ios::in | ios::binary);

    if (archivo.fail()){
        cout << "Ocurrio un error al abrir el archivo" << endl;
        exit(1);
    }
    else {
        //archivo.close();
        // cout << "Introduce el remitente a buscar: " << endl;
        // cin >> remi;

        //posición = NRR * (cantidad de bytes por registro) 
        int posicion ;
        //posicion = c.getId() * ()

        archivo.seekp(apuntadorCadena(f));
        // archivo.seekg(0);
        archivo.read((char* )&c, sizeof(Correo));
        archivo.close();
        //cin.getline(remi,20);
        cout << c.getRemitente() << endl;

        //if (remi == c.getRemitente()){

            cout << "Correo encontrado!" << endl;
            cout << "ID: " << c.getId() << endl;
            cout << "Remitente: " << c.getRemitente() << endl;
            cout << "Destinatario: " << c.getDestinatario() << endl;
            cout << "Copia carbono: " << c.getCopiaCarbono() << endl;
            cout << "Copia carbono ciega: " << c.getCopiaCarbonoCiega() << endl;
            cout << "Asunto: " << c.getAsunto() << endl;
            cout << "Contenido: " << c.getContenido() << endl;
        // }
        // else {
        //     cout << "No se pudo encontrar en correo" << endl;
        // }

        
    }
}
