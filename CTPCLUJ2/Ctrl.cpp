//
//  Ctrl.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 28/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Ctrl.hpp"
Ctrl::Ctrl(){
    
}
Ctrl::Ctrl(BazaDateClienti BC,BazaDateAutobuze BA){
    Clienti=BC;
    Autobuze=BA;
}
Ctrl::Ctrl(const Ctrl&C){
    Clienti=C.Clienti;
    Autobuze=C.Autobuze;
}
Ctrl& Ctrl::operator=(const Ctrl &C){
    if(this!=&C){
        Clienti=C.Clienti;
        Autobuze=C.Autobuze;
    }
    return *this;
}
Ctrl::~Ctrl(){
    
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
    Clienti.addClient(C);
}
void Ctrl::addAutobuz(Autobuz A){
    Autobuze.addElement(A);
}
void Ctrl::loadClienti(string filename){
    Clienti.LoadFromFile(filename);
}
