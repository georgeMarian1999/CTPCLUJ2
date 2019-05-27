#include "Autobuz.h"


Autobuz::Autobuz()
{

}
Autobuz::Autobuz(const Autobuz& a)
{
	this->numar = a.numar;
	this->orar = a.orar;
}
Autobuz::~Autobuz()
{

}
void Autobuz::setNumar(const int nr)
{
	this->numar = nr;
}
void Autobuz::setOrar(const Orar o)
{
	this->orar = o;
}
int Autobuz::getNumar()
{
	return this->numar;
}
Orar Autobuz::getOrar()
{
	return this->orar;
}
void Autobuz::addOra(Statie s, Ora o)
{
	this->orar.addStatieOra(s, o);

}

