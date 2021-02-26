#include"Playlist.hpp"

Playlist::Playlist() {

}
Playlist::Playlist(string nombre, vector<Cancion*>canciones) {
    this->nombre = nombre;
    this->canciones = canciones;
}
string Playlist::getNombre(){
    return nombre;
}

void Playlist::setNombre(string nombre){
    this->nombre = nombre;
}

vector<Cancion*> Playlist::getCanciones(){
    return canciones;
}

void Playlist::agregarCancion(Cancion* cancion){
    canciones.push_back(cancion);
}