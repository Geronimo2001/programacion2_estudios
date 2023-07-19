#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ManejadorArchivosTexto {
private:
    int espacios;
    int ocupados;
    int libres;
    float recaudados;
    float porcentaje;
public:
    ManejadorArchivosTexto(int esp, int lib, int ocu, float rec, float porc);
    void leerArchivo(string nombreArchivo);
    void escribirArchivo(string nombreArchivo, int esp, int lib, int ocu, float rec, float porc);
};

ManejadorArchivosTexto::ManejadorArchivosTexto(int esp, int lib, int ocu, float rec, float porc) {
    this->espacios = esp;
    this->libres = lib;
    this->ocupados = ocu;
    this->recaudados = rec;
    this->porcentaje = porc;
}

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


void ManejadorArchivosTexto::escribirArchivo(string nombreArchivo, int esp, int lib, int ocu, float rec, float porc) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << esp << endl;
        archivo << lib << endl;
        archivo << ocu << endl;
        archivo << rec << endl;
        archivo << porc << endl;

        archivo.close();
        cout << "Archivo guardado exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

class Estacionamiento {
private:
    ManejadorArchivosTexto registro;
    int espacios;
    int ocupados;
    int libres;
    float recaudados;
    float porcentaje;
public:
    Estacionamiento(ManejadorArchivosTexto reg, int esp, int ocu, int lib, float rec, float porc);
    void mostrarRegistro();
    void ingresarespacios(ManejadorArchivosTexto reg, int esp);
};

Estacionamiento::Estacionamiento(ManejadorArchivosTexto reg, int esp, int ocu, int lib, float rec, float porc)
        : registro(reg), espacios(esp), ocupados(ocu), libres(lib), recaudados(rec), porcentaje(porc) {
    // Aquí se realiza la inicialización de los miembros con los valores pasados como argumentos.
}

void Estacionamiento::mostrarRegistro() {
    cout << "Registro del Estacionamiento:" << endl;
    cout << "Espacios: " << espacios << endl;
    cout << "Ocupados: " << ocupados << endl;
    cout << "Libres: " << libres << endl;
    cout << "Recaudados: " << recaudados << endl;
    cout << "Porcentaje: " << porcentaje << endl;
}

void Estacionamiento::ingresarespacios(ManejadorArchivosTexto reg,int esp) {

    cout<<"Ingrese espacios totales:"<<endl;
    cin>>esp;
    reg.escribirArchivo(esp);

}

int main() {
    int espacios = 0;
    int ocupados = 0;
    int libres = 0;
    float recaudados = 0;
    float porcentaje = 0;
    int op;

    do {
        cout << "-----MENU DE OPCIONES-----" << endl;
        cout << "1)Ingrese cantidad de espacios en el estacionamiento" << endl;
        cout << "2)Ingrese cantidad de espacios libres en el estacionamiento" << endl;
        cout << "3)Ingrese cantidad de espacios ocupados en el estacionamiento" << endl;
        cout << "4)Ingrese cantidad recaudada" << endl;
        cout << "5)Ingrese porcentaje ocupado" << endl;
        cin>>op;
    } while(op!=0);




    ManejadorArchivosTexto manejador(espacios, libres, ocupados, recaudados, porcentaje);

    //estas objeto usalo adentro de la clases estacionamiento
    manejador.escribirArchivo("registro.txt", espacios, libres, ocupados, recaudados, porcentaje);

    Estacionamiento estacionamiento(manejador, espacios, ocupados, libres, recaudados, porcentaje);
    estacionamiento.mostrarRegistro();
    manejador.leerArchivo("registro.txt");

    return 0;
}
