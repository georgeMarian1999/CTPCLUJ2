/*
 * ClientLogat.cpp
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#include "ClientLogat.hpp"
ClientLogat::ClientLogat():Client(){
	//constructor without par
	this->username="";
	this->parola="";
	this->bilete=RepoBilete();
}

ClientLogat::ClientLogat(Card c, string u, string p, RepoBilete r):Client(c){
	//constructor with par
	this->parola=p;
	this->username=u;
	this->bilete=r;
}

ClientLogat::~ClientLogat(){
	//destructor
	this->username.clear();
	this->parola.clear();
}

string ClientLogat::getUserName(){

	return this->username;
}

string ClientLogat::getParola(){

	return this->parola;
}

RepoBilete ClientLogat::getBilete(){
	return this->bilete;
}

void ClientLogat::setUserName(string u){

	this->username=u;
}

void ClientLogat::setParola(string p){

	this->parola=p;
}

void ClientLogat::setBilete(RepoBilete r){

	this->bilete=r;
}

ClientLogat& ClientLogat::operator=(const ClientLogat& c){
	if (this != &c){
				Client::operator=(c);
				this->username=c.username;
				this->parola=c.parola;
				this->bilete=c.bilete;
			}
			return *this;
}


bool ClientLogat::operator==(const ClientLogat& c){

	return(this->username==c.username && this->parola==c.parola &&  this->bilete==c.bilete && this->infoCard==c.infoCard);
}

ClientLogat::ClientLogat(const ClientLogat& c):Client(c){

	this->username=c.username;
	this->parola=c.parola;
	this->bilete=c.bilete;
}
