/*
 * Client.h
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Card.h"

class Client{
private:
	Card infoCard;
public:
	Client();
	~Client();
	Client(Card);
	Client(const Client&);
	Card getInfoCard();
	void setCard(Card);
	Client& operator=(const Client &);
	bool operator==(const Client &);

};




#endif /* CLIENT_H_ */
