/*
 * BazaDateClienti.h
 *
 *  Created on: May 27, 2019
 *      Author: user
 */

#ifndef BAZADATECLIENTI_H_
#define BAZADATECLIENTI_H_
#include <fstream>
#include <string.h>
#include "Client.h"
#include <string>
#include <vector>
#include <iostream>
#include "RepoBilete.h"
#include "ClientLogat.hpp"
#include "Card.h"
using namespace std;
class BazaDateClienti{
private:
	vector<Client*> elements;
public:
	BazaDateClienti();
	BazaDateClienti(const BazaDateClienti &r);
	~BazaDateClienti();
	BazaDateClienti& operator=(const BazaDateClienti &r);
	int getSize();
	vector<Client*> getAll();
	void addClient(Client* el);
	void update(Client*, int);
    string toString();
	void LoadFromFile(string);
	void AddClient_File(string);
    bool operator==(const BazaDateClienti&);
    bool operator!=(const BazaDateClienti&);
	Client* getClient(int);
};





#endif /* BAZADATECLIENTI_H_ */
