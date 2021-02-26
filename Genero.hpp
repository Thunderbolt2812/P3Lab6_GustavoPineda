#pragma once
#ifndef GENERO_HPP
#define GENERO_HPP
#include<string>
#include<iostream>
using namespace std;
class Genero {
private:
	string nombre;
public:
	Genero();
	Genero(string);
	~Genero();
	string getNombre();
	void setNombre(string);

};
#endif