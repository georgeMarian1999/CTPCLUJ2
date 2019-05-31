/*
 * Bilet.cpp
 *
 *  Created on: May 26, 2019
 *      Author: user
 */
#include "Bilet.h"
#include<iostream>
using namespace std;

Bilet::Bilet(){
    //constructor
	this->pret=0;
	this->zona=0;
}

Bilet::~Bilet(){
    //destructor
}

Bilet::Bilet(int p, int z){
    //constructor cu parametrii
	this->pret=p;
	this->zona=z;
}

int Bilet::getPret(){
	return this->pret;
}

int Bilet::getZona(){
	return this->zona;
}

void Bilet::setPret(int p){
	this->pret=p;
}

void Bilet::setZona(int z){
	this->zona=z;
}

bool Bilet::operator==(const Bilet& b){
    //operator egal
	return (this->pret==b.pret && this->zona==b.zona);

}
ostream& operator<<(ostream &os, const Bilet &b){
	//operator de redirectare a iesirii

	os<< "Biletul are pretul "<<b.pret<<" si este pentru zona "<<b.zona <<endl;
	return os;
}
string Bilet::toString(){
    //Descriere:functie care returneaza un string care va fi forma cum este afisat biletul pe ecran
    //Input:
    //Output:un string
	string s;
		s=s+"Pret: "+to_string(this->pret)+" Zona: "+to_string(this->zona);
		return s;
}

