#include "Perro.h"
#include <iostream>
#include <string>

Perro::Perro(int id, int edad, string nombre, string raza, string tamanio, string color)
        : id(id), edad(edad), nombre(nombre), raza(raza), tamanio(tamanio), color(color) {}

Perro::~Perro() {
    cout << this->getNombre() <<" ya no está en el refugio" << endl;
}

// TO DO: modificar para que la info sea retornada y el main la pueda mostrar por consola.
string Perro::ladrar() {
    string texto = "Guau Guau, mi nombre es " + this->nombre + "\n";
    return texto;
}

int Perro::getId() {
    return this->id;
}

int Perro::getEdad() {
    return this->edad;
}

void Perro::setEdad(int edad) {
    this->edad = edad;
}

string Perro::getNombre() {
    return this->nombre;
}

void Perro::setNombre(string nombre) {
    this->nombre = nombre;
}

string Perro::getRaza() {
    return this->raza;
}

void Perro::setRaza(string raza) {
    this->raza = raza;
}

string Perro::getTamanio() {
    return this->tamanio;
}

void Perro::setTamanio(string tamanio) {
    this->tamanio = tamanio;
}

string Perro::getColor() {
    return this->color;
}

void Perro::setColor(string color) {
    this->color = color;
}
