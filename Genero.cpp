#include"Genero.hpp"

Genero::Genero(){
}
Genero::Genero(string genero) {
    this->genero = genero;
}
Genero::~Genero() {

}
string Genero::getGenero(){
    return genero;
}

void Genero::setNombre(string genero){
    this->genero = genero;
}
