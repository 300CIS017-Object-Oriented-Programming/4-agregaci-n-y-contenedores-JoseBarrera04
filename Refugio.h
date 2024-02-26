#ifndef INC_4_CONTENEDORAS_REFUGIO_H
#define INC_4_CONTENEDORAS_REFUGIO_H

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include "Perro.h"
#include "Propietario.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::make_pair;
using std::iterator;

class Refugio {
private:
    string nombre;
    int acumPerros;
    vector<Perro*> bdPerros;
    unordered_map<int,Perro*> mapaPerros;

public:
    Refugio()= default;
    ~Refugio();
    Refugio(string nombre);

    void agregarPerro(int id, int edad, string nombre, string raza, string tamanio, string color);
    void recibirPerro(int edad, string nombre, string raza, string tamanio, string color);
    void mostrarPerros();
    bool buscarPerro(int id);
    void listarPerrosPorEdad(int edad,int edadMayor);
    void darPerroEnAdopcion(int id, int idPropietario);

    int getAcumPerros();
    string getNombre();
    void setNombre(string nombre);
    vector<Perro *> getBdPerros();
    unordered_map<int, Perro *> getMapaPerros();

    Propietario *encontrarPropietario(int propietario);
};

#endif
