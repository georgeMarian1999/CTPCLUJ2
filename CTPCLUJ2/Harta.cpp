//
//  Harta.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 29/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Harta.hpp"
Harta::Harta(){
    
}
Harta::Harta(vector<Nod> X){
    Graf=X;
}
Harta::Harta(const Harta& H){
    Graf=H.Graf;
}
Harta& Harta::operator=(const Harta &H){
    if(this!=&H){
        Graf=H.Graf;
    }
    return *this;
}
Harta::~Harta(){
    Graf.clear();
}
vector<Nod> Harta::getGraf(){
    return Graf;
}
vector<string> Harta::getvecini(string nume){
    vector<string> vecini;
    int gasit=-1;
    int i=0;
    while(i<Graf.size()&&gasit==-1){
        if(Graf[i].getinfo()==nume)
            gasit=i;
        i++;
    }
    return Graf[gasit].getvecini();
}
void Harta::setAll(vector<Nod> N){
    Graf=N;
}
bool Harta::operator==(const Harta&H){
    if(Graf.size()!=H.Graf.size())
        return false;
    for(int i=0;i<Graf.size();i++)
        if(Graf[i]!=H.Graf[i])
            return false;
    return true;
}
string Harta::toString(){
    string s;
    s="Harta de statii este\n";
    for(int i=0;i<Graf.size();i++)
        s=s+Graf[i].toString()+"\n";
    return s;
}
