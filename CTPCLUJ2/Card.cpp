/*
 * Card.cpp
 *
 *  Created on: May 26, 2019
 *      Author: Ana
 */

#include"Card.h"
Card::Card(){
	//constructor without par
	nrCard=0;
	pin=0;
}

Card::~Card(){
	//destructor
}

Card::Card(int nr, int p){
	//constructor with par
	nrCard=nr;
    if(p>9999)
        throw Exception("Pin ul este prea lung.Incercati din nou");
    if(p<1000)
        throw Exception("Pin ul este prea scurt.Incercati din nou");
	pin=p;
}

Card::Card(const Card& c){
	//copy constructor
	this->nrCard=c.nrCard;
	this->pin=c.pin;
}

bool Card::operator==(const Card& c){
    //operator egal
	return (this->nrCard==c.nrCard && this->pin==c.pin);
}
bool Card::operator!=(const Card& c){
    //operator diferit
    return (!(this->nrCard==c.nrCard && this->pin==c.pin));
}
Card& Card::operator=(const Card& c){
    //constructor de atribuire
	if(this!=&c){
		this->nrCard=c.nrCard;
		this->pin=c.pin;
	}
	return *this;
}
int Card::getNrCard(){

	return this->nrCard;
}

int Card::getPin(){

	return this->pin;
}

void Card::setNrCard(int n){

	this->nrCard=n;
}

void Card::setPin(int p){

	this->pin=p;
}

ostream& operator<<(ostream &os, const Card &c){
	//operator de redirectare a iesirii

	os<< "Nr.card: "<<c.nrCard<<" Pin:"<<c.pin<<endl;
	return os;
}

string Card::toString(){
    //Descriere:functie care retureaza un string care va fi forma cum va arata cardul pe ecran
    //Input:--
    //Output:un string
	string s;
	s=s+to_string(this->nrCard)+" "+to_string(this->pin);
	return s;
}

