#include "Refugio.h"
#include "Perro.h"
#include "Propietario.h"
#include <vector>

Refugio::Refugio(string nombre) : acumPerros(1), nombre(nombre) {}

Refugio::~Refugio() {
    for (int indexVector = 0; indexVector < this->bdPerros.size(); indexVector++) {
        delete this->bdPerros[indexVector];
    }

    cout << "\n¡Gracias por visitarnos!" << endl;
}


void Refugio::agregarPerro(int id, int edad, string nombre, string raza, string tamanio, string color){
    Perro* perroP = new Perro(id, edad, nombre, raza, tamanio, color);
    bdPerros.push_back(perroP);
    mapaPerros.insert(make_pair(perroP->getId(),perroP));
}

void Refugio::recibirPerro(int edad, string nombre, string raza, string tamanio, string color) {
    Perro* pPerroTemp = new Perro(this->acumPerros, edad, nombre, raza, tamanio, color);

    bdPerros.push_back(pPerroTemp);

    mapaPerros.insert(make_pair(this->acumPerros, pPerroTemp));

    this->acumPerros++;
}

void Refugio::mostrarPerros() {
    vector<Perro*>::iterator itVector;
    unordered_map<int, Perro*>::iterator itMap;

    cout << "Los perros en el refugio son:\n";
    cout << "\nVECTOR\n";

    for (itVector = bdPerros.begin(); itVector != bdPerros.end(); ++itVector) {
        cout << "Id: "<< (*itVector)->getId() << endl << "Edad: "<<(*itVector)->getEdad() << endl << "Nombre: " << (*itVector)->getNombre() << endl << "Raza: " << (*itVector)->getRaza() << endl << "Tamanio: " << (*itVector)->getTamanio() << endl << "Color: " << (*itVector)->getColor() << endl;
    }

    cout << "\nMAP\n";
    for (itMap = mapaPerros.begin(); itMap != mapaPerros.end(); ++itMap) {
        cout << "Id: " << itMap->first << endl << "Nombre: " << itMap->second->getNombre() << endl << "Edad: " << itMap->second->getEdad() << endl << "Raza: " << itMap->second->getRaza() << endl << "Tamanio: " << itMap->second->getTamanio() << endl << "Color: " << itMap->second->getColor() << endl;
    }

}

bool Refugio::buscarPerro(int id) {
    bool found = false;
    int flag = 0;

    vector<Perro*>::iterator itVector;
    for (itVector = bdPerros.begin(); itVector != bdPerros.end() && flag == 0; ++itVector) {
        if ((*itVector)->getId() == id) {
            found = true;
            flag = 1;
        }
    }
    return found;
}

void Refugio::listarPerrosPorEdad(int edadMenor, int edadMayor) {
    vector<Perro*>::iterator itVector;
    for (itVector = bdPerros.begin(); itVector != bdPerros.end(); ++itVector) {
        if ((*itVector)->getEdad() <= edadMayor && (*itVector)->getEdad() >= edadMenor) {
            cout << "Id: " << (*itVector)->getId() << " Edad: " << (*itVector)->getEdad() << " Nombre: " << (*itVector)->getNombre() << " Raza: " << (*itVector)->getRaza() << " Tamanio: " << (*itVector)->getTamanio() << " Color: " << (*itVector)->getColor() << endl;
        }
    }
}


void Refugio::darPerroEnAdopcion(int idPerro, int idPropietario) {
    int found = 0;
    vector<Perro*>::iterator itPerro;

    for (itPerro = bdPerros.begin(); itPerro != bdPerros.end() && found == 0; ++itPerro) {
        if ((*itPerro)->getId() == idPerro) {
            found = 1;
            Propietario* propietario = encontrarPropietario(idPropietario);
            if (propietario != nullptr) {
                //Aqui me bugie
                //propietario->asociarPerro(*itPerro);
                bdPerros.erase(itPerro);
            } else {
                cout << "Propietario no encontrado." << endl;
            }
        }
    }
    if (found == 0) {
        cout << "Perro no encontrado." << endl;
    }
}

//Propietario *Refugio::encontrarPropietario(int propietario) {
//    return propietarioTemp;
//}

int Refugio::getAcumPerros() {
    return this->acumPerros;
}

string Refugio::getNombre() {
    return this->nombre;
}

void Refugio::setNombre(string nombre) {
    this->nombre = nombre;
}

vector<Perro *> Refugio::getBdPerros()  {
    return bdPerros;
}

unordered_map<int, Perro *> Refugio::getMapaPerros()  {
    return mapaPerros;
}
