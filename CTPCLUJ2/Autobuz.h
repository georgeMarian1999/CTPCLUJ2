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
    Autobuz& operator=(const Autobuz&);
	Autobuz(int, Orar);
	~Autobuz();
	int getNumar();
	Orar getOrar();
    bool operator==(const Autobuz&);
    bool operator!=(const Autobuz&);
    string toString();
	void setNumar(const int);
	void setOrar(Orar);
	int nr_Statii(string,string);
    bool isStatie(Statie);
    bool isStatie(string);
    int posStart(Statie,Statie);
};







#endif
