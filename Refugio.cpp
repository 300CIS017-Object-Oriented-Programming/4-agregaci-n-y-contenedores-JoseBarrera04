#include "Refugio.h"

// To Do: organizar todas las entradas y salidas de datos para que esta clase no tenga
// interacción con la consola, esa tarea será sólo responsabilidad del main

Refugio::Refugio(string nombre) : acumPerros(1), nombre(nombre) {}

Refugio::~Refugio() {
    // Recorremos el vector para eliminar los objetos. No sería necesario recorrer el map ya que se almacenaban los
    // mismos objetos y la referencia ya no existiría.
    for (int indexVector = 0; indexVector < this->bdPerros.size(); indexVector++) {
        delete this->bdPerros[indexVector];
    }

    cout << "\n¡Gracias por visitarnos!" << endl;
}

// TO DO: Completar
void Refugio::recibirPerro(int edad, string nombre, string raza, string tamanio, string color) {
    // Creo el objeto perro que voy a pasar a mi contenedor.
    Perro* pPerroTemp = new Perro(this->acumPerros, edad, nombre, raza, tamanio, color); // Creado en el heap

    // TO DO: Agregar el objeto al final de un vector.
    this->bdPerros.push_back(pPerroTemp);

    // TO DO: Agregar el objeto a un map de dos formas: Definiendo manualmente la llave o creando un par llave + referencia.
    //Ejemplo1: this-mapita[id] = referencia;
    this->mapaPerros[pPerroTemp->getId()] = pPerroTemp;

    //Ejemplo2: this->mapita.insert(make_pair(this->soyElID, soyLaReferencia));
    this->mapaPerros.insert(make_pair(pPerroTemp->getId(), pPerroTemp));

    this->acumPerros++; // incrementa el contador de perros
}

// TO DO: Completar
void Refugio::mostrarPerros() {
    vector<Perro*>::iterator itVector;
    unordered_map<int, Perro*>::iterator itMap;

    cout << "Los perros en el refugio son:\n";
    // Recorrer el vector
    cout << "\nVECTOR\n";
    for (itVector = bdPerros.begin(); itVector != bdPerros.end(); ++itVector) {
        cout << "Perro ID: " << (*itVector)->getId() << ", Nombre: " << (*itVector)->getNombre() << ", Edad: " << (*itVector)->getEdad() << endl;
    }

// Recorrer el map
    cout << "\nMAP\n";
    for (itMap = mapaPerros.begin(); itMap != mapaPerros.end(); ++itMap) {
        cout << "Perro ID: " << itMap->second->getId() << ", Nombre: " << itMap->second->getNombre() << ", Edad: " << itMap->second->getEdad() << endl;
    }

}


int Refugio::getAcumPerros() {
    return this->acumPerros;
}

string Refugio::getNombre() {
    return this->nombre;
}

void Refugio::setNombre(string nombre) {
    this->nombre = nombre;
}
