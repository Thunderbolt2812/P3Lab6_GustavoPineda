#include"Playlist.hpp"

Playlist::Playlist() {

}
Playlist::Playlist(string nombre, vector<Cancion*>canciones) {
    this->nombre = nombre;
    this->canciones = canciones;
}
Playlist::~Playlist(){
	
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
Playlist Playlist::operator+(Cancion c){
	Playlist res;
    vector<Cancion*> aux;
    aux = this->getCanciones();
    aux.push_back(&c);
    for(int i = 0;i<aux.size();i++){
    	Cancion* aux2 = aux.at(i);
    	res.agregarCancion(aux2);
	}
	return res;
}
Playlist Playlist::operator+(Album a){
	Playlist res;
    vector<Cancion*> aux;
    aux = this->getCanciones();
    for(int i = 0;i<a.getCanciones().size();i++){
    	Cancion* aux2 = a.getCanciones().at(i);
    	aux.push_back(aux2);
	}
    for(int i = 0;i<aux.size();i++){
    	Cancion* aux3 = aux.at(i);
    	res.agregarCancion(aux3);
	}
	return res;
}
Playlist Playlist::operator+(Playlist p){
	Playlist res;
    vector<Cancion*> aux;
    aux = this->getCanciones();
    for(int i = 0;i<p.getCanciones().size();i++){
    	Cancion* aux2 = p.getCanciones().at(i);
    	aux.push_back(aux2);
	}
    for(int i = 0;i<aux.size();i++){
    	Cancion* aux3 = aux.at(i);
    	res.agregarCancion(aux3);
	}
	return res;
}
Playlist Playlist::operator-(Cancion c){
	Playlist res;
    vector<Cancion*> aux;
    string nom = c.getNombre();
    aux = this->getCanciones();
    for(int i = 0;i<aux.size();i++){
    	Cancion* aux2 = aux.at(i);
    	string nom2 = aux2->getNombre();
    	if(nom==nom2){
    		aux.erase(aux.begin()+i);
		}
	}
	if(!aux.empty()){
		for(int i = 0;i<aux.size();i++){
			Cancion* aux3 = aux.at(i);
	    	res.agregarCancion(aux3);
    	}
    	return res;
	}else{
		cout<<"La playlist se vacio"<<endl;
		return res;
	}
}
Playlist Playlist::operator-(Genero g){
	Playlist res;
    vector<Cancion*> aux;
    string nom = g.getNombre();
    aux = this->getCanciones();
    for(int i = 0;i<aux.size();i++){
    	Cancion* aux2 = aux.at(i);
    	Genero* gen = aux2->getGenero_c();
    	string nom2 = gen->getNombre();
    	if(nom!=nom2){
    		res.agregarCancion(aux2);
		}
	}
	return res;
}