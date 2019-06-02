#include "Autobuz.h"


Autobuz::Autobuz()
{
    //constructor
    numar=0;
    Orar orar;
}
Autobuz::Autobuz(const Autobuz& a)
{
    //constructor cu parametrii
	this->numar = a.numar;
    this->orar=a.orar;
}
Autobuz& Autobuz::operator=(const Autobuz &a){
    //constructor de atribuire
    if(this!=&a){
        this->numar = a.numar;
        this->orar=a.orar;
    }
    return *this;
}
Autobuz::Autobuz(int nr,Orar r)
{
    //constructor de atribuire
	this->numar=nr;
    this->orar.setMatrice(r.getTimpi());
    this->orar.setStatii(r.getStatii());
}
Autobuz::~Autobuz()
{
    //destructor
}
bool Autobuz::operator==(const Autobuz &A){
    //operator egal
    if(numar!=A.numar)
        return false;
    return orar==A.orar;
}
bool Autobuz::operator!=(const Autobuz&A){
    //operator diferit
    if(numar==A.numar)
        return false;
    return orar!=A.orar;
}
string Autobuz::toString(){
    //Descriere:functie care stocheaza intr un string forma cum se va afisa autobuzul
    //input:--
    //output:un string 
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
    //D:returneaza numarul de statii dintre 2 statii
    //I:statia de pornire si sosire(string)
    //O:nr de statii
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
bool Autobuz::isStatie(Statie S){
    return orar.isStatie(S);
}
bool Autobuz::isStatie(string nume){
    return orar.isStatie(nume);
}
int Autobuz::posStart(Statie pornire, Statie oprire){
    return orar.posStart(pornire, oprire);
}
