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

class BazaDateAutobuze: public Repo<Autobuz>{
public:
	BazaDateAutobuze();
	BazaDateAutobuze(const vector<Autobuz> &);
	friend ostream& operator<<(ostream & , const BazaDateAutobuze& );
	BazaDateAutobuze& operator=(const BazaDateAutobuze&);
	bool operator==(const BazaDateAutobuze&);
	string toString();
};




#endif /* BAZADATEAUTOBUZE_H_ */
