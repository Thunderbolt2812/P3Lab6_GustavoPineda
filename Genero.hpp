#pragma once
#ifndef GENERO_HPP
#define GENERO_HPP
#include<string>
#include<iostream>
using namespace std;
class Genero {
private:
	string genero;
public:
	Genero();
	Genero(string);
	~Genero();
	string getGenero();
	void setGenero(string);
public:
    string getNombre();
    void setNombre(string);

};
#endif