/*
 * BazaDateAutobuze.h
 *
 *  Created on: May 28, 2019
 *      Author: user
 */

#ifndef BAZADATEAUTOBUZE_H_
#define BAZADATEAUTOBUZE_H_
#include "Autobuz.h"
#include <iostream>
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
    bool operator==(const BazaDateAutobuze&);
    bool operator!=(const BazaDateAutobuze&);
    string toString();
};




#endif /* BAZADATEAUTOBUZE_H_ */
