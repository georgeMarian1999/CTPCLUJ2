#include "Autobuz.h"


Autobuz::Autobuz()
{

}
Autobuz::Autobuz(Autobuz& a)
{
	this->numar = a.numar;
    this->orar .setMatrice(a.orar.getTimpi());
    this->orar.setStatii(a.orar.getStatii());
}
Autobuz::Autobuz(int nr,Orar r)
{
	this->numar=nr;
    this->orar.setMatrice(r.getTimpi());
    this->orar.setStatii(r.getStatii());
}
Autobuz::~Autobuz()
{
}
bool Autobuz::operator==(const Autobuz &A){
    if(numar!=A.numar)
        return false;
    return orar==A.orar;
}
bool Autobuz::operator!=(const Autobuz&A){
    if(numar==A.numar)
        return false;
    return orar!=A.orar;
}
string Autobuz::toString(){
    string s;
    s=s+"Autobuzul cu numarul "+to_string(numar)+" are orarul:\n";
    s=s+orar.toString();
    return s;
}
void Autobuz::setNumar(const int nr)
{
	this->numar = nr;
}
void Autobuz::setOrar( Orar o)
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


