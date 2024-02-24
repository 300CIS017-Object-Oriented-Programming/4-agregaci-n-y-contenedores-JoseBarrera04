#include <iostream>
#include "Perro.h"
#include "Refugio.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

void primeraOpcion(Refugio* refugio) {
    // TO DO
}

void terceraOpcion(Refugio* refugio) {
    // TO DO
}

void cuartaOpcion(Refugio* refugio) {
    // TO DO
}

void quintaOpcion(Refugio* refugio) {
    // TO DO
}

void mostrarMenu(Refugio* refugio) {
    int opc = 0;
    do
    {
        cout << "\n**** Bienvenidos al refugio - " << refugio->getNombre() << " ****\n";
        cout << "1. Registrar un nuevo perro\n";
        cout << "2. Mostrar todos los perros disponibles\n";
        cout << "3. Buscar un perro\n";
        cout << "4. Listar perros por edad\n";
        cout << "5. Dar un perro en adopcion\n";
        cout << "0. Salir\n" << endl;

        cin >> opc;

        switch (opc)
        {
            case 1:
                primeraOpcion(refugio);
                break;
            case 2:
                refugio->mostrarPerros();
                break;
            case 3:
                terceraOpcion(refugio);
                break;
            case 4:
                cuartaOpcion(refugio);
                break;
            case 5:
                quintaOpcion(refugio);
                break;
            default:
                break;
        }
    } while (opc != 0);
}

int main() {
    Refugio* pRefugio= new Refugio("Mi mascota feliz");
    mostrarMenu(pRefugio);

    // Debo usar el delete explicitamente cuando tengo objetos creados en el heap, ya que estos no se eliminan automáticamente.
    delete pRefugio;
    return 0;
}