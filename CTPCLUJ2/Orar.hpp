//
//  Orar.hpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Orar_hpp
#define Orar_hpp
#include <vector>
#include "Statie.hpp"
#include "Ora.hpp"
#include "Matrice.hpp"
using namespace std;
#include <stdio.h>
class Orar{
private:
    vector<Statie> Statii;
    Matrice Timpi;
public:
    Orar();
    Orar(vector<Statie>,Matrice);
    ~Orar();
    vector<Statie> getStatii();
    Ora getTimpi(int,int);
    int getnrcol();
    int getnrlin();
    vector<Ora> getTimpiStatie(Statie);
    Matrice getTimpi();
    void setStatii(vector<Statie>);
    void setTimpi(int,int,Ora);
    void setnrcol(int);
    void setnrlin(int);
    bool operator==(const Orar&);
    bool operator!=(const Orar&);
    void loadfromfile(string);
	void addStatieOra(Statie, Ora);
    //friend ostream& operator<<(ostream&,const Orar&);
};
#endif /* Orar_hpp */
