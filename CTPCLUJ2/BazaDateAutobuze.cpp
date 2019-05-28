/*
 * BazaDateAutobuze.cpp
 *
 *  Created on: May 28, 2019
 *      Author: user
 */
#include "BazaDateAutobuze.h"
BazaDateAutobuze::BazaDateAutobuze(){
    
}
BazaDateAutobuze::BazaDateAutobuze(vector<Autobuz> X){
    V=X;
}
BazaDateAutobuze::BazaDateAutobuze(const BazaDateAutobuze& B){
    V=B.V;
}
BazaDateAutobuze& BazaDateAutobuze:: operator=(const BazaDateAutobuze &B){
    if(this!=&B){
        V=B.V;
    }
    return *this;
}
BazaDateAutobuze::~BazaDateAutobuze(){
    
}
vector<Autobuz> BazaDateAutobuze::getall(){
    return V;
}
void BazaDateAutobuze::setall(vector<Autobuz> X){
    V=X;
}
bool BazaDateAutobuze::operator==(const BazaDateAutobuze &B){
    if(V.size()!=B.V.size())
        return false;
    for(int i=0;i<V.size();i++)
        if(V[i]!=B.V[i])
            return false;
    return true;
}
bool BazaDateAutobuze::operator!=(const BazaDateAutobuze &B){
    if(V.size()!=B.V.size())
        return true;
    for(int i=0;i<V.size();i++)
        if(V[i]!=B.V[i])
            return true;
    return false;
}
