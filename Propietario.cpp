#include "Propietario.h"
#include "Refugio.h"
#include <string>
using namespace std;

string Propietario::adoptarPerro(int idPerro, int idPropietario, Refugio* refugio){
    string text = "La adopcion fue exitosa";
    unordered_map<int,Perro*> pMapa = refugio->getMapaPerros();
    Perro* perroAux = pMapa.at(idPerro);

    if(perrosAdoptados.size() < 2){
        perrosAdoptados.push_back(perroAux);
        mapaPerrosAdoptados.insert(make_pair(idPropietario,perroAux));
    }else{
        text = "Solo se pueden adoptar dos perros como maximo";
    }
    return text;
}

bool Propietario::buscarPerroPropietario(int id){
    bool found = false;
    int flag = 0;

    for (auto itVector = perrosAdoptados.begin(); itVector != perrosAdoptados.end() && flag == 0; ++itVector) {
        if((*itVector)->getId() == id){
            found = true;
            flag = 1;
        }
    }

    return found;
}

void Propietario::borrarPerroPropietario(int idPerro, int idPropietario){
    int found = 0;
    for (auto itVector = perrosAdoptados.begin(); itVector != perrosAdoptados.end() && found == 0; ++itVector) {
        if((*itVector)->getId() == id){
            perrosAdoptados.erase(itVector);
            found = 1;
        }
    }
    if(found == 1){
        mapaPerrosAdoptados.erase(id);
    }
}

string Propietario::dondeEstaElPerro(int idPerro, Refugio* refugio){
    string mensaje;
    bool adoptado = false, ref = false;
    if(buscarPerroPropietario(idPerro) == true){
        adoptado = true;
    }else if(refugio->buscarPerro(idPerro) == true){
        ref = true;
    }

    if(adoptado == true && ref == false){
        mensaje = "El id del propietario del perro es " + to_string(this->getId()) + " y el nombre es " + this->getNombre() + "\n";
    }else if(adoptado == false && ref == true){
        mensaje = "El perro esta en el refugio";
    }else{
        mensaje = "El perro no esta en el refugio";
    }

    return mensaje;
}

int Propietario::getId() const {
    return id;
}

void Propietario::setId(int id) {
    Propietario::id = id;
}

string Propietario::getNombre() {
    return this->nombre;
}

void Propietario::setNombre(string nombre) {
    this->nombre = nombre;
}

Propietario::Propietario(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}
