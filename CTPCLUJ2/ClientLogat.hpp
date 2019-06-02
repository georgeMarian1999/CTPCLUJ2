/*
 * ClientLogat.hpp
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef CLIENTLOGAT_HPP_
#define CLIENTLOGAT_HPP_
#include "Client.h"
#include "RepoBilete.h"
class ClientLogat:public Client{
private:
	string username;
	string parola;
	RepoBilete bilete;
public:
	ClientLogat();
	ClientLogat(Card, string, string, RepoBilete);
	~ClientLogat();
	string getUserName();
	string getParola();
	RepoBilete getBilete();
	void setUserName(string);
	void setParola(string);
	void setBilete(RepoBilete);
	ClientLogat& operator=(const ClientLogat&);
	bool operator==(const ClientLogat&);
    bool operator!=(const ClientLogat&);
	ClientLogat(const ClientLogat&);
	string toString();
    void AddBilet(Bilet);
};




#endif /* CLIENTLOGAT_HPP_ */
