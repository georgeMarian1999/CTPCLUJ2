//
//  Statie.cpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Statie.hpp"
Statie::Statie(){
    zona=0;
}
Statie::Statie(string o,int m){
    nume=o;
    zona=m;
}
Statie::Statie(const Statie& A){
    nume=A.nume;
    zona=A.zona;
}
Statie& Statie::operator=(const Statie & A){
    if(this!=&A){
        nume=A.nume;
        zona=A.zona;
    }
    return *this;
}
Statie::~Statie(){
    
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
    return(nume==A.nume&&zona==A.zona);
}
bool Statie::operator!=(const Statie &A){
    if(nume!=A.nume||zona!=A.zona)
        return true;
    else return false;
}
ostream& operator<<(ostream& os,const Statie&A){
    os<<"Statia cu numele"<<" "<<A.nume<<" se afla in zona:"<<A.zona<<endl;
    return os;
}
