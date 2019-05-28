//
//  BazaDateAuto.cpp
//  
//
//  Created by Marian George on 28/05/2019.
//

#include "BazaDateAuto.hpp"
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
//void BazaDateAutobuze::addElement(Autobuz A){
  //  V.push_back(A);
//}
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
        if(!(V[i]==B.V[i]))
            return true;
    return false;
}
string BazaDateAutobuze::toString(){
    string s;
    for(int i=0;i<V.size();i++){
        s=s+V[i].toString();
        s=s+"\n";
    }
    return s;
}
