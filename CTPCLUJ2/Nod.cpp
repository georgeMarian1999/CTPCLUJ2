//
//  Nod.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 29/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Nod.hpp"
Nod::Nod(){
    //constructor
}
Nod::Nod(string i,vector<string> x){
    //constructor de parametrii
    info=i;
    Vecini=x;
}
Nod::Nod(const Nod& N){
    //constructor de atribuire
    info=N.info;
    Vecini=N.Vecini;
}
Nod& Nod::operator=(const Nod &N){
    //constructor de copiere
    if(this!=&N){
        info=N.info;
        Vecini=N.Vecini;
    }
    return *this;
}
Nod::~Nod(){
    //destructor
    info.clear();
    Vecini.clear();
}
string Nod::getinfo(){
    return info;
}
vector<string> Nod::getvecini(){
    return Vecini;
}
void Nod::setinfo(string i){
    info=i;
}
void Nod::setvecini(vector<string> v){
    Vecini=v;
}
bool Nod::operator==(const Nod &N){
    //operator egal
    return(info==N.info);
}
bool Nod::operator!=(const Nod &N){
    //operator diferit
    return(info!=N.info);
}
string Nod::toString(){
    //functie care transforma un nod intr un string
    //input:--
    //output:un string
    string s;
    s="Nodul "+info+" are vecinii: "+"\n";
    for(int i=0;i<Vecini.size();i++)
        s=s+Vecini[i]+" ";
    s=s+"\n";
    return s;
}
void Nod::addVecin(string vecin){
    //functie care adauga un vecin
    //input:un string
    //output:--
	this->Vecini.push_back(vecin);
}
