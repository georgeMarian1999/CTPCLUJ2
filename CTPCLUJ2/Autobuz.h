#pragma once
#ifndef AUTOBUZ_H
#define AUTOBUZ_H
#include "Orar.hpp"

class Autobuz {
private:
	int numar;
	Orar orar;
public:
	Autobuz();
	Autobuz(const Autobuz&);
	~Autobuz();
	int getNumar();
	Orar getOrar();
	void setNumar(const int);
	void setOrar(const Orar);
	void addOra(Statie, Ora);

};









#endif
