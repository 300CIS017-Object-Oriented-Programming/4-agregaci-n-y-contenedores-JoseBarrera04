#ifndef INC_4_CONTENEDORAS_PROPIETARIO_H
#define INC_4_CONTENEDORAS_PROPIETARIO_H

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include "Perro.h"
#include "Refugio.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::make_pair;
using std::iterator;

class Propietario {
private:
    int id;
    string nombre;
    vector<Perro*> perrosAdoptados;
    unordered_map<int,Perro*> mapaPerrosAdoptados;

public:
    Propietario(int id, string nombre);
    int getId() const;
    void setId(int id);
    string getNombre();
    void setNombre(string nombre);
    string adoptarPerro(int idPerro, int idPropietario, Refugio *refugio);
    void borrarPerroPropietario(int idPerro, int idPropietario);
    bool buscarPerroPropietario(int id);
    string dondeEstaElPerro(int idPerro, Refugio *refugio);
};
#endif //INC_4_CONTENEDORAS_PROPIETARIO_H