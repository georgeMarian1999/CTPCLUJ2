#include "Autobuz.h"


Autobuz::Autobuz()
{
    numar=0;
    Orar orar;
}
Autobuz::Autobuz(const Autobuz& a)
{
	this->numar = a.numar;
    this->orar=a.orar;
}
Autobuz& Autobuz::operator=(const Autobuz &a){
    if(this!=&a){
        this->numar = a.numar;
        this->orar=a.orar;
    }
    return *this;
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
int Autobuz::nr_Statii(string pornire, string sosire)
{
    bool found=false;
    int nr=1;
    for(unsigned int i=0;i<this->orar.getStatii().size();i+=1)
    {
        if(!found)
        {
            if(pornire==this->orar.getStatii()[i].getnume())
            {
                found = true;

            }

        }
        else{
            if(sosire==this->orar.getStatii()[i].getnume())
            {
                return nr+1;
            }
            nr+=1;
        }
    }
    return nr;
}


