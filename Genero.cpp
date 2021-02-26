#include"Genero.hpp"

Genero::Genero(){
}
Genero::Genero(string nombre) {
    this->nombre = nombre;
}
Genero::~Genero() {

}
string Genero::getNombre(){
    return nombre;
}

void Genero::setNombre(string nombre){
    this->nombre = nombre;
}
