//
//  Ora.cpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Ora.hpp"
Ora::Ora(){
    //constructor
    ora=0;
    minute=0;
}
Ora::Ora(int o,int m){
    //constructor cu parametrii
    if(o>24)
        throw Exception("Ora invalida!");
    if(m>60)
        throw Exception("Minute invalide");
    ora=o;
    minute=m;
}
Ora::Ora(const Ora& A){
    //constructor de atribuire
    ora=A.ora;
    minute=A.minute;
}
 Ora& Ora::operator=(const Ora & A){
     //constructor de copiere
    if(this!=&A){
        ora=A.ora;
        minute=A.minute;
    }
    return *this;
}
Ora::~Ora(){
    //destructor
}
int Ora::getora(){
    return ora;
}
int Ora::getminute(){
    return minute;
}
void Ora::setora(int o){
    ora=o;
}
void Ora::setminute(int m){
    minute=m;
}
bool Ora::operator==(const Ora &A){
    //operator egal
    return(ora==A.ora&&minute==A.minute);
}
bool Ora::operator!=(const Ora &A){
    //operator diferit
    if(ora!=A.ora||minute!=A.minute)
        return true;
    else return false;
}
bool Ora::operator>(const Ora &A){
    //operator mai mare
    if(ora>A.ora)
        return true;
    else if(ora<A.ora)
            return false;
     if(ora==A.ora){
        if(minute>A.minute)
            return true;
        else return false;
    }
    return false;
}
bool Ora::operator<(const Ora &A){
    //operator mai mic
    if(ora<A.ora)
        return true;
    else if(ora>A.ora)
        return false;
    if(ora==A.ora){
        if(minute<A.minute)
            return true;
        else return false;
    }
    return false;
}
string Ora::toString(){
    //functie care transforma o ora intr un string
    //input:--
    //output:un string
    string s;
    if(minute<10){
        s=s+to_string(ora)+":"+"0"+to_string(minute);
    }
    else
        s=s+to_string(ora)+":"+to_string(minute);
    return s;
}
