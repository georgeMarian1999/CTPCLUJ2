//
//  BazaDateAuto.cpp
//  
//
//  Created by Marian George on 28/05/2019.
//

#include "BazaDateAuto.hpp"
#include <fstream>
BazaDateAutobuze::BazaDateAutobuze(){
}
BazaDateAutobuze::BazaDateAutobuze(vector<Autobuz> X){
    V=X;
}
BazaDateAutobuze::BazaDateAutobuze(const BazaDateAutobuze& B){
    V=B.V;
}
BazaDateAutobuze& BazaDateAutobuze:: operator=(const BazaDateAutobuze &B){
    if(this!=&B){
        V=B.V;
    }
    return *this;
}
BazaDateAutobuze::~BazaDateAutobuze(){
    
}
vector<Autobuz> BazaDateAutobuze::getall(){
    return V;
}
void BazaDateAutobuze::setall(vector<Autobuz> X){
    V=X;
}
void BazaDateAutobuze::addElement(Autobuz A){
    V.push_back(A);
}
bool BazaDateAutobuze::operator==(const BazaDateAutobuze &B){
    if(V.size()!=B.V.size())
        return false;
    for(int i=0;i<V.size();i++)
        if(V[i]!=B.V[i])
            return false;
    return true;
}
bool BazaDateAutobuze::operator!=(const BazaDateAutobuze &B){
    if(V.size()!=B.V.size())
        return true;
    for(int i=0;i<V.size();i++)
        if(!(V[i]==B.V[i]))
            return true;
    return false;
}
string BazaDateAutobuze::toString(){
    string s;
    for(int i=0;i<V.size();i++){
        s=s+V[i].toString();
        s=s+"\n";
    }
    return s;
}
void BazaDateAutobuze::LoadFromFile(const char* filename)
{
    ifstream f(filename);
    string nrautobuz,nrStatii,nume,zona,ora,min,linie;
    string ultimaora,ultimmin;
    vector<vector<Ora>> Ore;
    vector<Ora> Aux;
    while(!f.eof()){
        getline(f,nrautobuz,'\n');
        getline(f,nrStatii,'\n');
        vector<Statie> Statii;
        for(int i=0;i<stoi(nrStatii);i++){
            getline(f,nume,',');
            getline(f,zona,'\n');
            Statie S;
            S.setnume(nume);
            S.setzona(stoi(zona));
            Statii.push_back(S);
        }
        Ore.clear();
        for(int i=0;i<8;i++){
            for(int j=1;j<stoi(nrStatii);j++){
                getline(f,ora,',');
                getline(f,min,' ');
                Ora O;
                O.setora(stoi(ora));
                O.setminute(stoi(min));
                Aux.push_back(O);
            }
            getline(f,ultimaora,',');
            getline(f,ultimmin,'\n');
            Ora O;
            O.setminute(stoi(ultimmin));
            O.setora(stoi(ultimaora));
            Aux.push_back(O);
            Ore.push_back(Aux);
            Aux.clear();

        }
        Orar OrarAux;
        OrarAux.setStatii(Statii);
        Matrice Mat(Ore);
        OrarAux.setMatrice(Mat);
        Autobuz A;
        A.setOrar(OrarAux);
        A.setNumar(stoi(nrautobuz));
        addElement(A);
    }

}

vector<Autobuz> BazaDateAutobuze::filterByNr(int nr){
	/*Descr:filtreaza autobuzele cu numarul nr
	 * In:nr
	 * Out:vector de autobuze cu prop ceruta
	 */
	vector<Autobuz> aux;
	for(int i=0;i<V.size();i++)
		if(V[i].getNumar()==nr)
			aux.push_back(V[i]);
	return aux;
}
vector<Autobuz> BazaDateAutobuze::filterByStatie(string name){
	/*Descr:filtreaza autobuzele care trec prin statia "name"
		 * In:name
		 * Out:vector de autobuze cu prop ceruta
		 */
	vector<Autobuz> aux;
	for(int i=0;i<V.size();i++)
		for(int j=0; j<V[i].getOrar().getStatii().size();j++)
			if(V[i].getOrar().getStatii()[j].getnume()==name){
				aux.push_back(V[i]);
				j=int(V[i].getOrar().getStatii().size());
			}
	return aux;


}
