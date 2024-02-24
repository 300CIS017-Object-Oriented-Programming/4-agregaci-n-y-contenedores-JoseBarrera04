#ifndef PERRO_H
#define PERRO_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Perro {
private:
    int id;
    int edad;
    string nombre;
    string raza;
    string tamanio;
    string color;
public:
    Perro() = default;
    Perro(int id, int edad, string nombre, string raza, string tamanio, string color);
    ~Perro();

    void ladrar();

    int getId();
    int getEdad();
    void setEdad(int edad);
    string getNombre();
    void setNombre(string nombre);
    string getRaza();
    void setRaza(string raza);
    string getTamanio();
    void setTamanio(string tamanio);
    string getColor();
    void setColor(string color);
};

#endif