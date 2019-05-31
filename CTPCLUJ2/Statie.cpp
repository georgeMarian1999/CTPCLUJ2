//
//  Statie.cpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Statie.hpp"
Statie::Statie(){
    //constructor
    zona=0;
}
Statie::Statie(string o,int m){
    //constructor cu parametrii
    nume=o;
    zona=m;
}
Statie::Statie(const Statie& A){
    //constructor de atribuire
    nume=A.nume;
    zona=A.zona;
}
Statie& Statie::operator=(const Statie & A){
    //constructor de copiere
    if(this!=&A){
        nume=A.nume;
        zona=A.zona;
    }
    return *this;
}
Statie::~Statie(){
    //destructor
}
string Statie::getnume(){
    return nume;
}
int Statie::getzona(){
    return zona;
}
void Statie::setnume(string o){
    nume=o;
}
void Statie::setzona(int m){
    zona=m;
}
bool Statie::operator==(const Statie &A){
    //operator de egal
    return(nume==A.nume&&zona==A.zona);
}
bool Statie::operator!=(const Statie &A){
    //operator diferit
    if(nume!=A.nume||zona!=A.zona)
        return true;
    else return false;
}
ostream& operator<<(ostream& os,const Statie&A){
    //operator de redirectionare a iesirii
    os<<"Statia cu numele"<<" "<<A.nume<<" se afla in zona:"<<A.zona<<endl;
    return os;
}
