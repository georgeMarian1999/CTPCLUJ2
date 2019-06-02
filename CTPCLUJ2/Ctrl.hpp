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
#include "Harta.hpp"
#include "Autobuz.h"
#include <stdio.h>
class Ctrl{
private:
    BazaDateClienti Clienti;
    BazaDateAutobuze Autobuze;
    Harta Traseu;
public:
    Ctrl();
    Ctrl(BazaDateClienti,BazaDateAutobuze,Harta);
    Ctrl(const Ctrl&);
    Ctrl& operator=(const Ctrl&);
    ~Ctrl();
    BazaDateClienti getClienti();
    BazaDateAutobuze getAutobuze();
    Harta getTraseu();
    vector<Autobuz> getvectAutoBuz();
    vector<Client*> getvectClienti();
    void setbazaclienti(BazaDateClienti);
    void setbazaauto(BazaDateAutobuze);
    void setTraseu(Harta);
    void addAutobuz(Autobuz);
    void addClient(Client*);
    void loadClienti(string);
    void loadAutobuze(string);
    vector<Autobuz> filterByNr(int);
    vector<Autobuz> filterByStatie(string);
    void create(BazaDateAutobuze);
    void addNod(Nod);
    void dijkstra(string start,string stop, vector<int>& dist, vector<string>& drum);
    void loadAutobuze(const char*);
    void AddClient_file(string);
    vector<Autobuz> traseuDirect(string start, string stop);
    vector<Autobuz> filterByStatii(string, string);
    void traseuIndirect(string start, string stop, vector<vector<Autobuz>>& rezFinal, vector<Statie>& coborare);
    Ora Fulger(Autobuz,Statie,Ora);

};
#endif /* Ctrl_hpp */
