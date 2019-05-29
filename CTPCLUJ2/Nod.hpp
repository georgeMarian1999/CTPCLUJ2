//
//  Nod.hpp
//  CTPCLUJ2
//
//  Created by Marian George on 29/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Nod_hpp
#define Nod_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Nod{
private:
    string info;
    vector<string> Vecini;
public:
    Nod();
    Nod(string,vector<string>);
    Nod(const Nod&);
    Nod& operator=(const Nod&);
    ~Nod();
    string getinfo();
    vector<string> getvecini();
    void setinfo(string);
    void setvecini(vector<string>);
    bool operator==(const Nod&);
    bool operator!=(const Nod&);
    string toString();
};
#endif /* Nod_hpp */
