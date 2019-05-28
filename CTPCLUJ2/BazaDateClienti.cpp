/*
 * BazaDateClienti.cpp
 *
 *  Created on: May 27, 2019
 *      Author: user
 */

#include"BazaDateClienti.h"
#include<fstream>
using namespace std;
#include<string.h>
#include"Client.h"
#include<vector>
#include<iostream>

BazaDateClienti::BazaDateClienti(){

	this->elements.reserve(10);
}


BazaDateClienti::BazaDateClienti(const BazaDateClienti &r){
	this->elements=r.elements;
}


BazaDateClienti::~BazaDateClienti(){
	elements.clear();
}


BazaDateClienti& BazaDateClienti::operator=(const BazaDateClienti &r){
	if (this != &r){
		elements.clear();
		elements.reserve(r.elements.size());
		for (int i = 0; i < r.elements.size(); i++)
			elements[i] = r.elements[i];
	}
	return *this;
}


int BazaDateClienti::getSize(){
	return int(elements.size());
}


vector<Client*> BazaDateClienti::getAll(){
	//if(pos<0 || pos>=elements.size())
//		throw Exception("pozitia trebuie sa fie intre 0 si dimensiunea vectorului...");
	return this->elements;
}


void BazaDateClienti::addClient(Client* el){

	elements.push_back(el);
}


void BazaDateClienti::update(Client* s, int pos){
	/*Descr:update pe pozitia pos cu obiectul s
	 * In:obiectul s, pozitia pos
	 * Out:-
	 */
	//if(pos<0 || pos>=elements.size())
	//	throw Exception("pozitia trebuie sa fie intre 0 si dimensiunea vectorului...");
	this->elements[pos]=s;
}


