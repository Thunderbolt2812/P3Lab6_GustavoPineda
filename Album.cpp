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
Album Album::operator*(int a){
	Album res;
	for(int i = 0;i<a;i++){
		for(int j = 0;j<res.getCanciones().size();j++){
			res.getCanciones().push_back(res.getCanciones().at(j));
		}
	}
	return res;
}
Album Album::operator+(Cancion c){
	Album res;
    vector<Cancion*> aux;
    aux = this->getCanciones();
    aux.push_back(&c);
    for(int i = 0;i<aux.size();i++){
    	Cancion* aux2 = aux.at(i);
    	res.agregarCancion(aux2);
	}
	return res;
}