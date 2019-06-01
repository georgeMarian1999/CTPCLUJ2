/*
 * Card.h
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef CARD_H_
#define CARD_H_
#include<iostream>
#include "Exception.hpp"
using namespace std;
class Card{
private:
	int nrCard;
	int pin;
public:
	Card();
	~Card();
	Card(int, int);
	Card(const Card&);
	bool operator==(const Card&);
    bool operator!=(const Card&);
	Card& operator=(const Card&);
	int getNrCard();
	int getPin();
	void setNrCard(int);
	void setPin(int);
	friend ostream& operator<<(ostream &os, const Card &);
	string toString();
};



#endif /* CARD_H_ */
