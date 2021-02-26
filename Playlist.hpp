#pragma once
#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include<iostream>
#include<vector>
#include"Genero.hpp"
#include"Cancion.hpp"
using namespace std;
class Playlist {
private:
	string nombre;
	vector<Cancion*> canciones;
public:
	Playlist();
	Playlist(string, vector<Cancion*>);
	~Playlist();
	string getNombre();
	vector<Cancion*> getCanciones();
	void agregarCancion(Cancion*);
	void setNombre(string);
};
#endif