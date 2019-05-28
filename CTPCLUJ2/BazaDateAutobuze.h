/*
 * BazaDateAutobuze.h
 *
 *  Created on: May 28, 2019
 *      Author: user
 */

#ifndef BAZADATEAUTOBUZE_H_
#define BAZADATEAUTOBUZE_H_
#include "Repo.h"
#include "Autobuz.h"
#include <iostream>
class BazaDateAutobuze: public Repo<Autobuz>{
public:
	BazaDateAutobuze();
	BazaDateAutobuze(const vector<Autobuz> &);
    ~BazaDateAutobuze();
	//friend ostream& operator<<(ostream & , const BazaDateAutobuze& );
	BazaDateAutobuze& operator=(BazaDateAutobuze&);
	bool operator==(const BazaDateAutobuze&);
	string toString();
};




#endif /* BAZADATEAUTOBUZE_H_ */
