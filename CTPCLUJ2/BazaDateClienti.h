/*
 * BazaDateClienti.h
 *
 *  Created on: May 27, 2019
 *      Author: user
 */

#ifndef BAZADATECLIENTI_H_
#define BAZADATECLIENTI_H_
using namespace std;
#include <iostream>
#include"Client.h"
#include<vector>
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
	void LoadFromFile(const char*);

};





#endif /* BAZADATECLIENTI_H_ */
