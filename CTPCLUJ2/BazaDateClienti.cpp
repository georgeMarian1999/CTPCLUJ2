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
	return elements.size();
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
void BazaDateClienti::LoadFromFile(const char* filename)
{
	ifstream f(filename);
	while(!f.eof())
	{
		char* string=new char[100];
		int nrcard,nrpin;
		char* username=new char[100];
		char* parola=new char[100];
		int pret, zona;
	
		f.getline(string,100);
		char* p=strtok(string,",");
		nrcard=atoi(p);
		p=strtok(NULL,",");
		nrpin=atoi(p);
		p=strtok(NULL,",");
		strcpy(username,p);
		p=strtok(NULL,",");
		strcpy(parola,p);
		p=strtok(NULL,",");
		Card cd(nrcard,nrpin);
		RepoBilete r;
		if(p)
		{
			while(p)
			{
				pret=atoi(p);
				p=strtok(NULL,",");
				zona=atoi(p);
				p=strtok(NULL,",");
				Bilet b(pret,zona);
				r.addElement(b);
			}
		}
		Client* c=new ClientLogat(username,parola,r);
		this->addClient(c);


		f.close();



	}
}


