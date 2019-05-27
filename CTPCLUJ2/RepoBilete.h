/*
 * RepoBilete.h
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef REPOBILETE_H_
#define REPOBILETE_H_
#include "Repo.h"
#include "Bilet.h"

class RepoBilete: public Repo<Bilet>{
public:
	friend ostream& operator<<(ostream & , const RepoBilete& );
	RepoBilete& operator=(const RepoBilete&);
	friend ostream& operator<<(ostream & , const RepoBilete& );
	RepoBilete& operator=(const RepoBilete&);
	bool operator==(const RepoBilete&);
};




#endif /* REPOBILETE_H_ */
