#include "Perro.h"
#include <iostream>

Perro::Perro(int id, int edad, string nombre, string raza, string tamanio, string color)
        : id(id), edad(edad), nombre(nombre), raza(raza), tamanio(tamanio), color(color) {}

Perro::~Perro() {
    cout << this->getNombre() << " Ya no se encuentra en el refugio" << endl;
}

string Perro::ladrar() {
    string mensaje = "Guau Guau, mi nombre es " + this->nombre;
    return mensaje;
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
