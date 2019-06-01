//
//  BazaDateAuto.cpp
//  
//
//  Created by Marian George on 28/05/2019.
//

#include "BazaDateAuto.hpp"
#include <fstream>
BazaDateAutobuze::BazaDateAutobuze(){
    //constructor
}
BazaDateAutobuze::BazaDateAutobuze(vector<Autobuz> X){
    //constructor cu parametrii
    V=X;
}
BazaDateAutobuze::BazaDateAutobuze(const BazaDateAutobuze& B){
    //constructor de atribuire
    V=B.V;
}
BazaDateAutobuze& BazaDateAutobuze:: operator=(const BazaDateAutobuze &B){
    //constructor de copiere
    if(this!=&B){
        V=B.V;
    }
    return *this;
}
BazaDateAutobuze::~BazaDateAutobuze(){
    //destructor
}
vector<Autobuz> BazaDateAutobuze::getall(){
    return V;
}
void BazaDateAutobuze::setall(vector<Autobuz> X){
    V=X;
}
void BazaDateAutobuze::addElement(Autobuz A){
    //adauga un autobuz in baza de date
    V.push_back(A);
}
bool BazaDateAutobuze::operator==(const BazaDateAutobuze &B){
    //operator egal
    if(V.size()!=B.V.size())
        return false;
    for(int i=0;i<V.size();i++)
        if(V[i]!=B.V[i])
            return false;
    return true;
}
bool BazaDateAutobuze::operator!=(const BazaDateAutobuze &B){
    //operator diferit
    if(V.size()!=B.V.size())
        return true;
    for(int i=0;i<V.size();i++)
        if(!(V[i]==B.V[i]))
            return true;
    return false;
}
string BazaDateAutobuze::toString(){
    //functie care transforma baza de date intr un string
    //input:--
    //output:string
    string s;
    for(int i=0;i<V.size();i++){
        s=s+V[i].toString();
        s=s+"\n";
    }
    return s;
}
void BazaDateAutobuze::LoadFromFile(const char* filename)

{
    //functie care incarca date din fisier
    //input:numele fisierului
    //output:--
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
Ora BazaDateAutobuze::diferent(Ora A, Ora B){
    //functie care face diferenta intre 2 ore
    int difora=abs(A.getora()-B.getora());
    int difmin=abs(A.getminute()-B.getminute());
    Ora O(difora,difmin);
    return O;
}
Ora BazaDateAutobuze::minima(vector<Ora> V,Ora O){
    Ora OraMinima;
    OraMinima.setora(24);
    OraMinima.setminute(60);
    int i=0;
    while(i<V.size()&&(V[i]<O||V[i]==O))
        i++;
    return V[i];
}
vector<int> BazaDateAutobuze::filterByTime(Statie S, Ora O){
    Ora OraMinima;
    OraMinima.setora(24);
    OraMinima.setminute(60);
    for(int i=0;i<V.size();i++){
        if(minima(V[i].getOrar().getTimpiStatie(S), O)<OraMinima){
            OraMinima=minima(V[i].getOrar().getTimpiStatie(S), O);
        }
    }
    vector<int> X;
    for(int i=0;i<V.size();i++){
        if(minima(V[i].getOrar().getTimpiStatie(S), O)==OraMinima){
            X.push_back(V[i].getNumar());
        }
    }
    return X;
}
vector<int> BazaDateAutobuze::filterByTime2(Statie S, Ora O){
    vector<int> x;
    x.clear();
    vector<Ora> L;
    L.clear();
    for(int i=0;i<V.size();i++){
        int j=0;
        x.push_back(V[i].getNumar()); while((j<V[i].getOrar().getTimpiStatie(S).size()&&(V[i].getOrar().getTimpiStatie(S)[j]<O))||V[i].getOrar().getTimpiStatie(S)[j]==O)
            j++;
        L.push_back(V[i].getOrar().getTimpiStatie(S)[j]);
    }
    for(int g=0;g<x.size();g++)
        cout<<x[g]<<" ";
    cout<<endl;
    for(int y=0;y<L.size();y++)
        cout<<L[y].toString()<<" ";
    cout<<endl;
    for(int k=0;k<L.size()-1;k++)
        for(int i=k+1;i<L.size();i++)
            if(L[k]>L[i])
            {
                Ora OraAux;
                OraAux=L[k];
                L[k]=L[i];
                L[i]=OraAux;
                int aux;
                aux=x[k];
                x[k]=x[i];
                x[i]=aux;
            }
    return x;
}
