#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ManejadorArchivosTexto {
private:
    int contenido;

public:

    ManejadorArchivosTexto(int cont);
    void leerArchivo(string nombreArchivo);
    void escribirArchivo(int contenido);

};
void ManejadorArchivosTexto::leerArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}


void ManejadorArchivosTexto::escribirArchivo(int cont) {
    ofstream archivo("C:\\Users\\geronimo\\OneDrive\\Escritorio\\Programacion 2\\trabajos-practicos-a1-v1-Geronimo2001\\u4\\ej01\\registro.txt",std::ios::app);
    if (archivo.is_open()) {

        archivo<<"Recaudado:";
        archivo << cont<<" $\n";
        archivo.close();
        cout << "Archivo guardado exitosamente." <<endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

ManejadorArchivosTexto::ManejadorArchivosTexto(int cont) {
    this->contenido=cont;
}

// Resto del código de la clase ManejadorArchivosTexto...

class Estacionamiento {
private:

    int recaudado;
    int espacios;
    int egresos;
    int ingresos;
    float porcentaje;
    ManejadorArchivosTexto registro;

public:
    Estacionamiento(int rec, int esp, int ocu, int lib, float porc,ManejadorArchivosTexto registro);
    void inicializarEspacios();
    void inicializarlibres();
    void espaciosocupados();
    void salidaDeAutos();
};
Estacionamiento::Estacionamiento(int rec, int esp, int ocu, int lib, float porc, ManejadorArchivosTexto registro) : registro(rec) {
    this->recaudado = rec;
    this->espacios = esp;
    this->egresos = ocu;
    this->ingresos = lib;
    this->porcentaje = porc;
}

// Resto del código de la clase Estacionamiento...

void Estacionamiento::inicializarEspacios() {
    cout << "Ingrese la cantidad de espacios que tiene el estacionamiento: ";
    cin >> espacios;
    ingresos = espacios;
}

void Estacionamiento::inicializarlibres() {
    int acumulador=0;
    cout << "Cuantos autos ingresaron: ";
    cin >> ingresos;
    acumulador=acumulador+ingresos;
    ingresos=acumulador;

    if(ingresos >espacios) {
        cout << "no hay suficientes espacios" << endl;
    }else {
        espacios=espacios- ingresos;
        cout<<"espacios guardados"<<endl;


    }




}

void Estacionamiento::espaciosocupados() {

    int acum=0;

    cout << "Cuantos autos egresaron : "<<endl;
    cin>>egresos;




    if(egresos>espacios){
        cout<<"No hay autos suficientes"<<endl;
    }else{
        acum=acum+egresos;
        egresos=acum;
        espacios=espacios+egresos;
        cout<<"AUTOS EGRESADOS CORRRECTAMENTE"<<endl;
    }

}
void Estacionamiento::salidaDeAutos() {
    int precio=200;
    int total;
    total=egresos*precio;
    cout<<"el total recaudado es : " << total << endl;
    registro.escribirArchivo(total);


}

int main() {
    int recaudados = 0;
    int espacios = 0;
    int ocupados = 0;
    int libres = 0;
    float porcentaje = 0;
    ManejadorArchivosTexto registro(recaudados);

    Estacionamiento estacionamiento(recaudados, espacios, ocupados, libres, porcentaje,registro);

    int op;

    do {
        cout << "-----MENU DE OPCIONES-----" << endl;
        cout << "1) Cantidad de espacios en el estacionamiento" << endl;
        cout << "2) Regsitrar ingreso del auto en el estacionamiento" << endl;
        cout << "3) Regsitrar egreso del estacionamiento" << endl;
        cout << "4) Cantidad recaudada" << endl;
        cout << "5) Porcentaje ocupado" << endl;
        cout << "6)salir"<<endl;
        cout << "Ingrese una opcion: "<<endl;
        cin>>op;

        switch (op) {
            case 1:
                estacionamiento.inicializarEspacios();
                break;
            case 2:
                estacionamiento.inicializarlibres();
                break;
            case 3:
                estacionamiento.espaciosocupados();
                break;
            case 4:
                estacionamiento.salidaDeAutos();
                break;
            case 5:
                cout << "Ha seleccionado la Opción 5." << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                return 0; // Sale del programa
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;

    } while (op != 6);

    return 0;
}
