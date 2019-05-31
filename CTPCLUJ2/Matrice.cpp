//
//  AlfaMatrix.cpp
//  CTPCluj
//
//  Created by Marian George on 26/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Matrice.hpp"
Matrice::Matrice(){
    //constructor
    nrlinii=0;
    nrcol=0;
}
Matrice::Matrice(vector<vector<Ora>> X){
    //constructor cu parametrii
    nrlinii=int(X.size());
    for(int i=0;i<nrlinii;i++)
        nrcol=int(X[i].size());
    V=X;
}
Matrice::Matrice(const Matrice&M){
    //constructor de atribuire
    nrlinii=M.nrlinii;
    nrcol=M.nrcol;
    V=M.V;
}
Matrice& Matrice::operator=(const Matrice &M){
    //constructor de copiere
    if(this!=&M){
        nrlinii=M.nrlinii;
        nrcol=M.nrcol;
        V.clear();
        V=M.V;
    }
    return *this;
}
Matrice::~Matrice(){
    //destructor
}
Ora& Matrice::getElem(int lin, int col){
    return V[lin][col];
}
Ora& Matrice::operator()(int lin,int col){
    return V[lin][col];
}
vector<vector<Ora>> Matrice::getAll(){
    return V;
}
int Matrice::getnrlin()const{
    return nrlinii;
}
int Matrice::getnrcol()const{
    return nrcol;
}
void Matrice::setnrlin(int n){
    nrlinii=n;
}
void Matrice::setnrcol(int m){
    nrcol=m;
}
void Matrice::setElem(int n, int m, Ora O){
    V[n][m]=O;
}
bool Matrice::operator==(const Matrice &M){
    //operator ==
    int ok=0;
    if(nrlinii!=M.nrlinii)
        return false;
    if(nrcol!=M.nrcol)
        return false;
    for(int i=0;i<nrlinii;i++)
        for(int j=0;j<nrcol;j++)
            if(V[i][j]==M.V[i][j])
                ok++;
    if(ok==nrlinii*nrcol)
        return true;
    return false;
}
bool Matrice::operator!=(const Matrice &M){
    //operator diferit
    int ok=0;
    for(int i=0;i<nrlinii;i++)
        for(int j=0;j<nrcol;j++)
            if(V[i][j]==M.V[i][j])
                ok++;
    if(ok==nrlinii*nrcol)
        return false;
    return true;
}
string Matrice::toString(){
    //functie care transforma o matrice intr un string
    //input:--
    //output:string s
    string s;
    for(int i=0;i<nrlinii;i++){
        for(int j=0;j<nrcol;j++)
            s=s+V[i][j].toString()+" ";
        s=s+"\n";
    }
    return s;
}
