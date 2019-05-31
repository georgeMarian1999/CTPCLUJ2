//
//  Ctrl.hpp
//  CTPCLUJ2
//
//  Created by Marian George on 28/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Ctrl_hpp
#define Ctrl_hpp
#include "BazaDateClienti.h"
#include "BazaDateAuto.hpp"
#include "Autobuz.h"
#include <stdio.h>
class Ctrl{
private:
    BazaDateClienti Clienti;
    BazaDateAutobuze Autobuze;
public:
    Ctrl();
    Ctrl(BazaDateClienti,BazaDateAutobuze);
    Ctrl(const Ctrl&);
    Ctrl& operator=(const Ctrl&);
    ~Ctrl();
    BazaDateClienti getClienti();
    BazaDateAutobuze getAutobuze();
    vector<Autobuz> getvectAutoBuz();
    vector<Client*> getvectClienti();
    void setbazaclienti(BazaDateClienti);
    void setbazaauto(BazaDateAutobuze);
    void addAutobuz(Autobuz);
    void addClient(Client*);
    void loadClienti(string);
    void loadAutobuze(string);
    vector<Autobuz> filterByNr(int);
    vector<Autobuz> filterByStatie(string);
    void loadAutobuze(const char*);
    void AddClient_file(Client*);

};
#endif /* Ctrl_hpp */
