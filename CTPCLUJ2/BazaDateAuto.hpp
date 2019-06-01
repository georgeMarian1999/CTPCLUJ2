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
    Ora diferent(Ora,Ora);
    Ora minima(vector<Ora>,Ora);
    vector<int> filterByTime(Statie,Ora);
    vector<Autobuz> filterByStatii(string, string);
};
#endif /* BazaDateAuto_hpp */
