//
//  Ora.hpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Ora_hpp
#define Ora_hpp

#include <stdio.h>
#include <string>
#include "Exception.hpp"
#include <iostream>
using namespace std;
class Ora{
private:
    int ora;
    int minute;
public:
    Ora();
    Ora(int,int);
    Ora(const Ora&);
    Ora& operator=(const Ora&);
    ~Ora();
    int getora();
    int getminute();
    void setora(int);
    void setminute(int);
    bool operator==(const Ora&);
    bool operator!=(const Ora&);
    bool operator>(const Ora&);
    bool operator<(const Ora&);
    string toString();
    friend istream& operator>>(istream& is,Ora&);
};
#endif /* Ora_hpp */
