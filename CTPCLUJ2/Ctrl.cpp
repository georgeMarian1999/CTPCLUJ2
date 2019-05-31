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
Ctrl::Ctrl(BazaDateClienti BC,BazaDateAutobuze BA,Harta H){
    //constructor cu parametrii
    Clienti=BC;
    Autobuze=BA;
    Traseu=H;
}
Ctrl::Ctrl(const Ctrl&C){
    //constructor de copiere
    Clienti=C.Clienti;
    Autobuze=C.Autobuze;
    Traseu=C.Traseu;
}
Ctrl& Ctrl::operator=(const Ctrl &C){
    //construtor de atribuire
    if(this!=&C){
        Clienti=C.Clienti;
        Autobuze=C.Autobuze;
        Traseu=C.Traseu;
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
Harta Ctrl::getTraseu(){
    return Traseu;
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
void Ctrl::setTraseu(Harta H){
    Traseu=H;
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

void Ctrl::create(BazaDateAutobuze B){
    //functie care apeleaza crearea un harte de autobuze
    Traseu.create(B);
}
void Ctrl::addNod(Nod N){
    //functie care apeleaza o functie a hartii care adauga un nod
    Traseu.addNod(N);
}
void Ctrl::dijkstra(string start, string stop, vector<int> &dist, vector<string> &drum){
    Traseu.dijkstra(start, stop, dist, drum);
}
void Ctrl::loadAutobuze(const char* filename){
    //functie care citeste baza de date de autobuze din fisier
    //input:numele fisierului
    //output:--
    Autobuze.LoadFromFile(filename);
}
void Ctrl::AddClient_file(string s)
    //functie care da update la baza de date a clientilor
{
    this->Clienti.AddClient_File(s);
}
vector<Autobuz> Ctrl::traseuDirect(string start, string stop){
	/*Descr:returneaza autobuzele care
	 * In:
	 * Out:
	 */
	vector<int> distante;
	vector<string> drum;
	dijkstra(start, stop, distante, drum);
	int nrStatii=drum.size();
	vector<Autobuz> aux;
	for(int i=0; i< Autobuze.filterByStatii(start, stop).size();i++)
		if(Autobuze.filterByStatii(start, stop)[i].nr_Statii(start, stop)==nrStatii)
			aux.push_back(Autobuze.filterByStatii(start, stop)[i]);

	return aux;

}
vector<Autobuz> Ctrl::filterByStatii(string start, string stop){
	/*Descr:filtreaza autobuzele care trec prin statia "start" si "stop"
			* In:start, stop
			* Out:vector de autobuze cu prop ceruta
			 */
	return Autobuze.filterByStatii(start, stop);
}


void Ctrl::traseuIndirect(string start, string stop, vector<vector<Autobuz>>& rezFinal, vector<Statie>& coborare){
	/*Descr:
	 * In:
	 * Out:
	 */
	vector<Autobuz> rezPartial;

	vector<int> distante;
	vector<string> drum;
	dijkstra(start, stop, distante, drum);

	vector<Autobuz> aux1;
	for(int i=0; i<Autobuze.filterByStatie(start).size(); i++)   //adauga in aux1 autobuzele care trec prin statia start
		aux1.push_back(Autobuze.filterByStatie(start)[i]);

	for(int i=0; i<aux1.size();i+=1)
	{	rezPartial.push_back(aux1[i]);
		for(int j=0;j<aux1[i].getOrar().getStatii().size();j+=1)
		{
			Statie intermediara=aux1[i].getOrar().getStatii()[j];
			bool found=false;
			for(int l=0; l<drum.size(); l++)
				if(drum[l]==intermediara.getnume())
					found=true;

			if(found){
			for(int k=0; k<Autobuze.filterByStatii(intermediara.getnume(), stop).size(); k++){
				rezPartial.push_back(Autobuze.filterByStatii(intermediara.getnume(), stop)[k]);
				rezFinal.push_back(rezPartial);
				coborare.push_back(intermediara);
				rezPartial.pop_back();
			}
			}

		} //end for j
		rezPartial.clear();

	}
}

