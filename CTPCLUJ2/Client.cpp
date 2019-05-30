/*
 * Client.cpp
 *
 *  Created on: May 26, 2019
 *      Author: user
 */
#include "Client.h"

Client::Client(){
	//constructor without par
	this->infoCard=Card();
}

Client::~Client(){

}

Client::Client(Card c){
	//constructor with par
	this->infoCard=c;
}

Client::Client(const Client& c){
	//copy constructor
	this->infoCard=c.infoCard;
}

Card Client::getInfoCard(){

	return this->infoCard;
}

void Client::setCard(Card c){

	this->infoCard=c;
}

Client& Client::operator=(const Client &c){
	if(this!=&c){
		this->infoCard=c.infoCard;
	}
	return *this;
}

bool Client::operator==(const Client &c){

	return(this->infoCard==c.infoCard);
}
bool Client::operator!=(const Client &c){
    return  (!(this->infoCard==c.infoCard));
}
RepoBilete Client::getBilete(){
    RepoBilete R;
    return R;
}
string Client::getParola(){
    return "parola";
}
string Client::getUserName(){
    return "Username";
}
string Client::toString(){
	string s;
	s=this->infoCard.toString()+"\n";
	return s;
}

