//
//  Orar.cpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Orar.hpp"
Orar::Orar(){
    
}
Orar::Orar(vector<Statie> V,Matrice A){
    Statii=V;
    for(int i=0;i<A.getnrlin();i++)
        for(int j=0;j<A.getnrcol();j++)
            Timpi(i,j)=A(i, j);
}
Orar::~Orar(){
    Statii.clear();
}
vector<Statie> Orar::getStatii(){
    return Statii;
}
Ora Orar::getTimpi(int NrStatie, int Parcurs){
    return Timpi(NrStatie,Parcurs);
}
int Orar::getnrcol(){
    return Timpi.getnrcol();
}
int Orar::getnrlin(){
    return Timpi.getnrlin();
}
vector<Ora> Orar::getTimpiStatie(Statie S){
    int found=-1;
    int i=0;
    while(i<Statii.size()&&found==-1)
    {
        if(Statii[i]==S)
            found=i;
        i++;
    }
    vector<Ora> o;
    for(int j=0;j<Timpi.getnrcol();j++)
        o.push_back(Timpi(found,j));
    return o;
}
void Orar::setStatii(vector<Statie> V){
    Statii=V;
}
void Orar::setTimpi(int pos1, int pos2, Ora O){
    Timpi(pos1,pos2)=O;
}
void Orar::setnrlin(int n){
    Timpi.setnrlin(n);
}
void Orar::setnrcol(int m){
    Timpi.setnrcol(m);
}
Orar& Orar::operator=(Orar& r)
{
    this->Statii=r.Statii;
    for(int i=0;i<this->Timpi.getnrlin();i+=1)
        for(int j=0;j<this->Timpi.getnrcol();j+=1)
        {
            this->Timpi(i,j)=r.Timpi(i,j);

        }
    return *this;

}
/*bool Orar::operator==(const Orar &O){
    for(int i=0;i<Statii.size();i++)
        if(Statii[i]!=O.Statii[i])
            return false;
    return O.Timpi.operator==();
}
bool Orar::operator!=(const Orar &O){
    for(int i=0;i<Statii.size();i++)
        if(Statii[i]==O.Statii[i])
            return false;
    for(int j=0;j<Statii.size();j++)
        for(int k=0;k<O.Timpi.getnrcol();k++)
            if(Timpi(j,k)==O.Timpi(j,k))
                return false;
    return true;
}
ostream& operator<<(ostream& os,const Orar& O){
    for(int i=0;i<O.Statii.size();i++)
    {
        os<<"Autobuzul ajunge in statia:"<<endl<<O.Statii[i];
        os<<"la orele: "<<endl;
        for(int j=0;j<O.Timpi.getnrcol();j++)
            os<<O.Timpi(i,j);
        os<<endl;
    }
    return os;
}*/
