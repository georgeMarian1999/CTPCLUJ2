/*
 * Bilet.h
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef BILET_H_
#define BILET_H_
#include<iostream>
using namespace std;

class Bilet{
private:
	int pret;
	int zona;
public:
	Bilet();
	~Bilet();
	Bilet(int, int);
	int getPret();
	int getZona();
	void setPret(int);
	void setZona(int);
	bool operator==(const Bilet&);
	friend ostream& operator<<(ostream &os, const Bilet &);
	string toString();
};




#endif /* BILET_H_ */
