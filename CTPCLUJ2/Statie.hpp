//
//  Statie.hpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Statie_hpp
#define Statie_hpp
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class Statie{
private:
    string nume;
    int zona;
public:
    Statie();
    Statie(string,int);
    Statie(const Statie&);
    Statie& operator=(const Statie&);
    ~Statie();
    string getnume();
    int getzona();
    void setnume(string);
    void setzona(int);
    bool operator==(const Statie&);
    bool operator!=(const Statie&);
    friend ostream& operator<<(ostream&,const Statie&);
};
#endif /* Statie_hpp */
