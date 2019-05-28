//
//  AlfaMatrix.hpp
//  CTPCluj
//
//  Created by Marian George on 26/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef AlfaMatrix_hpp
#define AlfaMatrix_hpp
#include <time.h>
#include <stdio.h>
#include "Ora.hpp"
#include <vector>
using namespace std;
class Matrice{
protected:
    int nrlinii;
    int nrcol;
    vector<vector<Ora> > V;
public:
    Matrice();
    Matrice(vector<vector<Ora> >);
    Matrice(const Matrice&);
    Matrice& operator=(const Matrice&);
    ~Matrice();
    Ora& operator()(int,int);
    vector<vector<Ora> > getAll();
    Ora& getElem(int,int);
    int getnrlin()const;
    int getnrcol()const;
    void setnrlin(int);
    void setnrcol(int);
    void setElem(int,int,Ora);
    bool operator==(const Matrice&);
    bool operator!=(const Matrice&);
    string toString();
    
};
#endif /* AlfaMatrix_hpp */
