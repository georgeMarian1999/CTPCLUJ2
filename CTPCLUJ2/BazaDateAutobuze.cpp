/*
 * BazaDateAutobuze.cpp
 *
 *  Created on: May 28, 2019
 *      Author: user
 */
#include "BazaDateAutobuze.h"
BazaDateAutobuze& BazaDateAutobuze::operator=(BazaDateAutobuze& r){
	if(this!=&r){
		this->vect.clear();
		for(int i=0; i<r.vect.size();i++)
			this->vect.push_back(r.vect[i]);
	}
	return *this;
}

bool BazaDateAutobuze::operator==(const BazaDateAutobuze& r){
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
BazaDateAutobuze::~BazaDateAutobuze(){
    
}
BazaDateAutobuze::BazaDateAutobuze(const vector<Autobuz> & vect):Repo<Autobuz>(vect){

}
BazaDateAutobuze::BazaDateAutobuze():Repo<Autobuz>(){

}
string BazaDateAutobuze::toString(){
	string str;
	for(int i=0; i<this->vect.size();i++)
		str=str+this->vect[i].toString()+"\n";
	return str;
}



