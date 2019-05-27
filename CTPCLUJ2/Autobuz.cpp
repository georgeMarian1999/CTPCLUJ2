#include "Autobuz.h"


Autobuz::Autobuz()
{

}
Autobuz::Autobuz(const Autobuz& a)
{
	this->numar = a.numar;
	this->orar = a.orar;
}
Autobuz::Autobuz(int nr, Orar r)
{
	this->numar=nr;
	this->orar=r;
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


