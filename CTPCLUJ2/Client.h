/*
 * Client.h
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Card.h"
#include "RepoBilete.h"
class Client{
protected:
	Card infoCard;
public:
	Client();
	~Client();
	Client(Card);
	Client(const Client&);
	Card getInfoCard();
	void setCard(Card);
	Client& operator=(const Client &);
	virtual bool operator==(const Client &);
    virtual bool operator!=(const Client&);
    virtual RepoBilete getBilete();
    virtual string getParola();
    virtual string getUserName();
	virtual string toString();
    virtual void AddBilet(Bilet){}

};
#endif /* CLIENT_H_ */
