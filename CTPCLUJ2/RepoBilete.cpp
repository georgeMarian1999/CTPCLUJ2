/*
 * RepoBilete.cpp
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#include "RepoBilete.h"
#include "iostream"
using namespace std;

ostream& operator<<(ostream& os, const RepoBilete &r){
    //operator de redirectionare a iesirii
	for(int i=0; i<r.vect.size(); i++)
		os<<r.vect[i];
	return os;
}

RepoBilete& RepoBilete::operator=(const RepoBilete& r){
    //constructor de copiere
	if(this!=&r){
		this->vect.clear();
		for(int i=0; i<r.vect.size();i++)
			this->vect.push_back(r.vect[i]);
	}
	return *this;
}

bool RepoBilete::operator==(const RepoBilete& r){
    //operator egal
	int ok=0;
	if(this->vect.size()!=r.vect.size())
		return false;
	else
		for(int i=0; i<this->vect.size();i++)
			if(this->vect[i]==r.vect[i])
				ok++;
	if(ok==this->vect.size())
		return true;
	else
		return false;
}

RepoBilete::RepoBilete(const vector<Bilet> & vect):Repo<Bilet>(vect){
    //constructor cu parametrii

}
RepoBilete::RepoBilete():Repo<Bilet>(){
    //constructor
}
string RepoBilete::toString(){
    //functie care transforma un repo de bilete intr un string
    //input::--
    //output:un string
	string str;
	for(int i=0; i<this->vect.size();i++)
		str=str+this->vect[i].toString()+"\n";
	return str;
}

