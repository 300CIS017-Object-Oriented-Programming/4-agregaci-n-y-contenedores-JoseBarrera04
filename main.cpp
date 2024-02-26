#include <iostream>
#include "Perro.h"
#include "Refugio.h"
#include "Propietario.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

void primeraOpcion(Refugio* refugio,int id) {
    int edad;
    string nombre, raza, tamanio, color;
    cout << "Escribe los datos del perro" << endl << endl;

    cout << "Edad:" << endl;
    cin >> edad;
    cout << "Nombre: " << endl;
    cin >> nombre;
    cout << "Raza:" << endl;
    cin>>raza;
    cout << "Tamanio:" << endl;
    cin >> tamanio;
    cout << "Color" << endl;
    cin >> color;
    refugio->agregarPerro(id,edad,nombre, raza, tamanio, color);
}

void terceraOpcion(Refugio* refugio) {
    int id;
    cout << "ID del Perro: " << endl;
    cin >> id;
    bool found = refugio->buscarPerro(id);

    cout << (found ? "El perro está en el refugio" : "El perro no está en el refugio") << endl;
}

void cuartaOpcion(Refugio* refugio) {
    int edadMinima, edadMaxima;
    cout << "Edad Minima: "<< endl;
    cin >> edadMinima;
    cout << "Edad Maxima: "<< endl;
    cin >> edadMaxima;
    refugio->listarPerrosPorEdad(edadMinima,edadMaxima);
}

void quintaOpcion(Refugio* refugio) {
    int id, idPropietario;
    cout << "Escribe el id del perro que desas dar en adopcion: " << endl;
    cin >> id;
    cout << "Escribe el id del propietario: " << endl;
    cin >> idPropietario;
    refugio->darPerroEnAdopcion(id, idPropietario);
}

void sextaOpcion(Propietario* propietario, Refugio* refugio){
    int idPerro, idPropietario;
    cout << "Escribe el id del perro: "<< endl;
    cin >> idPerro;
    cout << "Escribe el id del propietario" << endl;
    cin >> idPropietario;
}

void septimaOpcion(Propietario* propietario){
    int idPerro, idPropietario;
    cout << "Escribe el id del perro: "<< endl;
    cin >> idPerro;
    cout << "Escribe el id del propietario" << endl;
    cin >> idPropietario;
    propietario->borrarPerroPropietario(idPerro,idPropietario);
}
void octavaOpcion(Propietario* propietario, Refugio* refugio){
    int idPerro;
    cout << "Escribe el id del perro: "<< endl;
    cin >> idPerro;
    string text = propietario->dondeEstaElPerro(idPerro,refugio);
    cout << text << endl;

}
void mostrarMenu(Refugio* refugio, Propietario* propietario) {
    int opc = 0;
    int id = 1;
    do
    {
        cout << "\n**** Bienvenidos al refugio - " << refugio->getNombre() << " ****\n";
        cout << "1. Registrar un nuevo perro\n";
        cout << "2. Mostrar todos los perros disponibles\n";
        cout << "3. Buscar un perro\n";
        cout << "4. Listar perros por edad\n";
        cout << "5. Dar un perro en adopcion\n";
        cout << "6. Adoptar un perro\n";
        cout << "7. Borrar perro fallecido\n";
        cout << "8. Saber donde esta el perro\n";
        cout << "0. Salir\n" << endl;

        cin >> opc;

        switch (opc)
        {
            case 0: {
                cout << "Saliendo del programa\n";
                break;
            }

            case 1: {
                primeraOpcion(refugio, id);
                id++;
                break;
            }

            case 2: {
                refugio->mostrarPerros();
                break;
            }

            case 3: {
                terceraOpcion(refugio);
                break;
            }

            case 4: {
                cuartaOpcion(refugio);
                break;
            }

            case 5: {
                quintaOpcion(refugio);
                break;
            }

            case 6: {
                sextaOpcion(propietario, refugio);
                break;
            }

            case 7: {
                septimaOpcion(propietario);
                break;
            }

            case 8: {
                octavaOpcion(propietario,refugio);
                break;
            }

            default:
                cout << "Opcion no valida\n";
                break;
        }
    } while (opc != 0);
}

int main() {
    Refugio* pRefugio= new Refugio("El Arca de Noe");
    Propietario* propietario = new Propietario(1, "Juan");

    mostrarMenu(pRefugio,propietario);

    delete pRefugio;
    return 0;
}
