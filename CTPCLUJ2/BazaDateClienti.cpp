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
#include "RepoBilete.h"
#include "Card.h"
#include <string>
#include "ClientLogat.h"

BazaDateClienti::BazaDateClienti() {

	this->elements.reserve(10);
}


BazaDateClienti::BazaDateClienti(const BazaDateClienti &r) {
	this->elements = r.elements;
}


BazaDateClienti::~BazaDateClienti() {
	elements.clear();
}


BazaDateClienti& BazaDateClienti::operator=(const BazaDateClienti &r) {
	if (this != &r) {
		elements.clear();
		elements.reserve(r.elements.size());
		for (unsigned int i = 0; i < r.elements.size(); i++)
			elements[i] = r.elements[i];
	}
	return *this;
}


int BazaDateClienti::getSize() {
	return elements.size();
}


vector<Client*> BazaDateClienti::getAll() {
	//if(pos<0 || pos>=elements.size())
//		throw Exception("pozitia trebuie sa fie intre 0 si dimensiunea vectorului...");
	return this->elements;
}


void BazaDateClienti::addClient(Client* el) {

	elements.push_back(el);
}


void BazaDateClienti::update(Client* s, int pos) {
	/*Descr:update pe pozitia pos cu obiectul s
	 * In:obiectul s, pozitia pos
	 * Out:-
	 */
	 //if(pos<0 || pos>=elements.size())
	 //	throw Exception("pozitia trebuie sa fie intre 0 si dimensiunea vectorului...");
	this->elements[pos] = s;
}
void BazaDateClienti::LoadFromFile(const char* filename)
{


	ifstream f("BazaDateClienti.txt");
	while (!f.eof())
	{
		char* string = new char[100];
		char*nrcard = new char[100];
		char* nrpin = new char[100];
		char* username = new char[100];
		char* parola = new char[100];
		int pret, zona;

		f.getline(string, 100);
		int Nrcard = atoi(strtok_s(string, ",", &nrpin));
		int Nrpin = atoi(strtok_s(nrpin, ",", &username));
		username = strtok_s(username, ",", &parola);
		parola = strtok_s(parola, ",", &nrcard);
		
		Card cd(Nrcard, Nrpin);
		RepoBilete r;
		
		if (nrcard)
		{
			pret = nrcard[0] - '0';
			zona = nrcard[2] - '0';
			r.addElement(Bilet(pret, zona));
		}
		
		Client* c = new ClientLogat(cd, username, parola, r);
		this->addClient(c);
		

		cout << c->toString();

	}
	f.close();
}


