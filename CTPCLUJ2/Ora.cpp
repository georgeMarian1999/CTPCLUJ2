//
//  Ora.cpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Ora.hpp"
Ora::Ora(){
    ora=0;
    minute=0;
}
Ora::Ora(int o,int m){
    ora=o;
    minute=m;
}
Ora::Ora(const Ora& A){
    ora=A.ora;
    minute=A.minute;
}
 Ora& Ora::operator=(const Ora & A){
    if(this!=&A){
        ora=A.ora;
        minute=A.minute;
    }
    return *this;
}
Ora::~Ora(){
    
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
    return(ora==A.ora&&minute==A.minute);
}
bool Ora::operator!=(const Ora &A){
    if(ora!=A.ora||minute!=A.minute)
        return true;
    else return false;
}
bool Ora::operator>(const Ora &A){
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
    string s;
    s=s+to_string(ora)+":"+to_string(minute);
    return s;
}
