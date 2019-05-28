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
	Autobuz(Autobuz&);
    Autobuz& operator=(Autobuz&);
	Autobuz(int, Orar);
	~Autobuz();
	int getNumar();
	Orar getOrar();
    bool operator==(const Autobuz&);
    bool operator!=(const Autobuz&);
    string toString();
	void setNumar(const int);
	void setOrar(Orar);
};

//cacat







#endif
