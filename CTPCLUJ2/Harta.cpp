//
//  Harta.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 29/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Harta.hpp"
Harta::Harta(){
    
}
Harta::Harta(vector<Nod> X){
    Graf=X;
}
Harta::Harta(const Harta& H){
    Graf=H.Graf;
}
Harta& Harta::operator=(const Harta &H){
    if(this!=&H){
        Graf=H.Graf;
    }
    return *this;
}
Harta::~Harta(){
    Graf.clear();
}
vector<Nod> Harta::getGraf(){
    return Graf;
}
vector<string> Harta::getvecini(string nume){
    vector<string> vecini;
    int gasit=-1;
    int i=0;
    while(i<Graf.size()&&gasit==-1){
        if(Graf[i].getinfo()==nume)
            gasit=i;
        i++;
    }
    return Graf[gasit].getvecini();
}
void Harta::setAll(vector<Nod> N){
    Graf=N;
}
bool Harta::operator==(const Harta&H){
    if(Graf.size()!=H.Graf.size())
        return false;
    for(int i=0;i<Graf.size();i++)
        if(Graf[i]!=H.Graf[i])
            return false;
    return true;
}
string Harta::toString(){
    string s;
    s="Harta de statii este\n";
    for(int i=0;i<Graf.size();i++)
        s=s+Graf[i].toString()+"\n";
    return s;
}
void Harta::addNod(Nod n){
	Graf.push_back(n);
}
int Harta::searchNodWithGivenInfo(string info){
	/*Descr:cauta nodul care are ca informatie "info"
	 * In:string info
	 * Out:pozitia/-1 daca nu exista
	 */
	for(int i=0; i<Graf.size();i++)
		if(Graf[i].getinfo()==info)
			return i;
	return -1;
}
void Harta::create(BazaDateAutobuze baza){
	/*Descr:construieste un obiect de tip harta pe baza traseului fiecarui autobuz din baza de date de autobuze
	 * In:baza de date de autobuze
	 * Out:-
	 */
	for(int i=0; i<baza.getall().size();i++)
		for(int j=1; j<baza.getall()[i].getOrar().getStatii().size();j++) { //parcurgere vector<Statie>
			if(searchNodWithGivenInfo(baza.getall()[i].getOrar().getStatii()[j-1].getnume())==-1 ){
				Nod newNod;
				newNod.setinfo(baza.getall()[i].getOrar().getStatii()[j-1].getnume());
				addNod(newNod);
			}
			if(!(searchVecinforGivenNod(baza.getall()[i].getOrar().getStatii()[j-1].getnume(), baza.getall()[i].getOrar().getStatii()[j].getnume())))
				Graf[searchNodWithGivenInfo(baza.getall()[i].getOrar().getStatii()[j-1].getnume())].addVecin(baza.getall()[i].getOrar().getStatii()[j].getnume());
		}
}

bool Harta::searchVecinforGivenNod(string info, string vecin){
	/*Descr:verifica daca nodul cu informatia info are in vectorul de vecini string ul "vecin"
	 * In:Informatia nodului, vecinul de cautat
	 * Out:T/F
	 */
	int pos=searchNodWithGivenInfo(info);
	if(pos>=0)
		for( int i=0; i<Graf[pos].getvecini().size();i++)
			if(Graf[pos].getvecini()[i]==vecin)
				return true;
	return false;
}

void Harta::dijkstra(string start, vector<int>& dist){

	const int infinit=1000000;
	dist=vector<int>(Graf.size(), infinit);
	priority_queue<pereche> Coada;
	dist[searchNodWithGivenInfo(start)]=0;
	Coada.push({start, 0});
	int i;

	while(!Coada.empty()){

		string x=Coada.top().node;
		int dx=Coada.top().dist;
		i=0;
		Coada.pop();
		if(dx<=dist[searchNodWithGivenInfo(x)])

			for(int i=0; i<Graf[searchNodWithGivenInfo(x)].getvecini().size();i++){

				string y=Graf[searchNodWithGivenInfo(x)].getvecini()[i];

				if(dist[ searchNodWithGivenInfo(y) ] > dist[ searchNodWithGivenInfo(x)] + 1){
					dist[ searchNodWithGivenInfo(y) ]=dist[ searchNodWithGivenInfo(x) ]+1;
					Coada.push( {y, dist[searchNodWithGivenInfo(y)] } );


				}


	}


}
}
