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
string BazaDateClienti::toString(){
    string s;
    for(int i=0;i<elements.size();i++)
        s=s+elements[i]->toString();
    return s;
}
void BazaDateClienti::LoadFromFile(string filename)
{
    ifstream f;
    f.open(filename);
    if(!f)
        cout<<"error"<<endl;
    string nrclienti;
    getline(f,nrclienti,'\n');
    cout<<nrclienti<<endl;
    for(int i=0;i<stoi(nrclienti);i++){
        Card cd;
        string nrcard,pin,username,parola,nrbilete,pret,zona;
        RepoBilete r;
        getline(f,nrcard,',');
        getline(f,pin,',');
        getline(f,username,',');
        getline(f,parola,',');
        getline(f,nrbilete,',');
        for(int i=0;i<stoi(nrbilete);i++)
        {
            getline(f,pret,',');
            getline(f,zona,',');
            Bilet B(stoi(pret),stoi(zona));
            r.addElement(B);
        }
        string end;
        getline(f,end,'\n');
        cd.setNrCard(stoi(nrcard));
        cd.setPin(stoi(pin));
		Client* c=new ClientLogat(cd,username,parola,r);
		this->addClient(c); 
    }
		f.close();
	}
bool BazaDateClienti::operator==(const BazaDateClienti &R){
    if(elements.size()!=R.elements.size())
        return false;
    for(int i=0;i<elements.size();i++)
        if(elements[i]!=R.elements[i])
            return false;
    return true;
}
bool BazaDateClienti::operator!=(const BazaDateClienti &R){
    if(elements.size()!=R.elements.size())
        return true;
    for(int i=0;i<elements.size();i++)
        if(elements[i]!=R.elements[i])
            return true;
    return false;
}

