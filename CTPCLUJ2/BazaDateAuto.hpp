//
//  BazaDateAuto.hpp
//  
//
//  Created by Marian George on 28/05/2019.
//

#ifndef BazaDateAuto_hpp
#define BazaDateAuto_hpp

#include <stdio.h>
#include "Autobuz.h"
#include <iostream>
#include <time.h>
class BazaDateAutobuze{
private:
    vector<Autobuz> V;
public:
    BazaDateAutobuze();
    BazaDateAutobuze(vector<Autobuz>);
    BazaDateAutobuze& operator=(const BazaDateAutobuze&);
    BazaDateAutobuze(const BazaDateAutobuze&);
    ~BazaDateAutobuze();
    vector<Autobuz> getall();
    void setall(vector<Autobuz>);
    void addElement(Autobuz);
    bool operator==(const BazaDateAutobuze&);
    bool operator!=(const BazaDateAutobuze&);
    string toString();
    void LoadFromFile(const char*);
    vector<Autobuz> filterByNr(int);
    vector<Autobuz> filterByStatie(string);
    vector<Autobuz> filterByStatii(string, string);
    vector<Autobuz> filterByTime(Statie,Statie,Ora);
    bool esteAutobuz(int);
    bool esteStatie(string);
    Ora Fulger(Autobuz,Statie,Ora);
};
#endif /* BazaDateAuto_hpp */
