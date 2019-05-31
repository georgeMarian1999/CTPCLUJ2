//
//  Ctrl.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 28/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Ctrl.hpp"
Ctrl::Ctrl(){
    //contructor
}
Ctrl::Ctrl(BazaDateClienti BC,BazaDateAutobuze BA){
    //constructor cu parametrii
    Clienti=BC;
    Autobuze=BA;
}
Ctrl::Ctrl(const Ctrl&C){
    //constructor de copiere
    Clienti=C.Clienti;
    Autobuze=C.Autobuze;
}
Ctrl& Ctrl::operator=(const Ctrl &C){
    //construtor de atribuire
    if(this!=&C){
        Clienti=C.Clienti;
        Autobuze=C.Autobuze;
    }
    return *this;
}
Ctrl::~Ctrl(){
    //destructor
}
BazaDateClienti Ctrl::getClienti(){
    return Clienti;
}
BazaDateAutobuze Ctrl::getAutobuze(){
    return Autobuze;
}
vector<Autobuz> Ctrl::getvectAutoBuz(){
    return Autobuze.getall();
}
vector<Client*> Ctrl::getvectClienti(){
    return Clienti.getAll();
}
void Ctrl::setbazaclienti(BazaDateClienti b){
    Clienti=b;
}
void Ctrl::setbazaauto(BazaDateAutobuze b){
    Autobuze=b;
}
void Ctrl::addClient(Client *C){
    //functie care adauga un client in baza de date de clienti
    //Input:o adresa spre un client
    //Output:--
    Clienti.addClient(C);
}
void Ctrl::addAutobuz(Autobuz A){
    //functie care adauga un autobuz in baza de date de autobuze
    //input:un autobuz
    //output:--
    Autobuze.addElement(A);
}
void Ctrl::loadClienti(string filename){
    //functie care citeste o baza de date de clienti din fisier
    //input:un string care este numele fisierului
    //output:--
    Clienti.LoadFromFile(filename);
}

vector<Autobuz> Ctrl::filterByNr(int nr){
	/*Descr:filtreaza autobuzele cu numarul nr
		 * In:nr
		 * Out:vector de autobuze cu prop ceruta
		 */
	return this->Autobuze.filterByNr(nr);
}

vector<Autobuz> Ctrl::filterByStatie(string name){
	/*Descr:filtreaza autobuzele care trec prin statia "name"
			 * In:name
			 * Out:vector de autobuze cu prop ceruta
			 */
	return this->Autobuze.filterByStatie(name);
}


void Ctrl::loadAutobuze(const char* filename){
    //functie care citeste baza de date de autobuze din fisier
    //input:numele fisierului
    //output:--
    Autobuze.LoadFromFile(filename);
}
void Ctrl::AddClient_file(Client* c)
{
    this->Clienti.AddClient_File("DataBase1.csv",c);
}

