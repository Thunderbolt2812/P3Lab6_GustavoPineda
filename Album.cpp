#include "Album.hpp"
Album::Album() {

}
Album::Album(string nombre,string artistaA,vector<Cancion*> canciones) {
    this->nombre = nombre;
    this->artistaA = artistaA;
    this->canciones = canciones;
}
string Album::getNombre(){
    return nombre;
}

void Album::setNombre(string nombre){
    this->nombre = nombre;
}

string Album::getArtistaA(){
    return artistaA;
}

void Album::setArtistaA(int numA,string artista){
    if (numA!=0) {
        artistaA = "Varios Artistas";
    }
    else {
        artistaA = artista;
    }
}

Album::~Album() {
    for (int i = 0;i<canciones.size();i++) {
        delete canciones.at(i);
    }
    canciones.clear();
}

vector<Cancion*> Album::getCanciones(){
    return canciones;
}

void Album::agregarCancion(Cancion* cancion){
    canciones.push_back(cancion);
}