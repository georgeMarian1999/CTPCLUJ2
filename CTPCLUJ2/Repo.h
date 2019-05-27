/*
 * Repo.h
 *
 *  Created on: May 26, 2019
 *      Author: user
 */

#ifndef REPO_H_
#define REPO_H_

#include<iostream>
#include<vector>
using namespace std;

template <class T> class Repo{
protected:
	vector<T> vect;
public:
	Repo();
	Repo(const vector<T> &);
	Repo(const Repo <T> &);
	~Repo();
	void addElement(T);
	vector<T> getAll();
	void update(T, int);
	int getSize();
	friend ostream& operator<<(ostream & , const Repo<T>& );

};

template <class T> Repo<T>::Repo(){
	//constructor without par
	this->vect.reserve(10);
}

template <class T> Repo <T>::Repo(const vector<T> &v){
	//constructor with par
 	this->vect.clear();
 	for(int i=0; i<v.size(); i++)
 		this->vect.push_back(v[i]);
}

template <class T> Repo<T>::Repo(const Repo<T> &V){
	//copy constructor
	this->vect.clear();
	for(int i=0; i<V.vect.size(); i++)
		 this->vect.push_back(V.vect[i]);

}

template <class T> Repo<T>::~Repo(){
	//destructor
	this->vect.clear();

}

template <class T> void Repo<T>::addElement(T e){
/*Descr:adauga un element in vector
 * In:element de tip T
 * Out:vectorul modificat
 */
	this->vect.push_back(e);
}

template <class T> vector<T> Repo<T>::getAll(){
/*Descr:returneaza vectorul
 * In:-
 * Out:vectorul
 */

	return this->vect;
}

template <class T> int Repo<T>::getSize() {
/*Descr:returneaza nr de elemente din vector
 * In:-
 * Out:nr de elem
 */
	return this->vect.size();
}

template <class T> ostream& operator<<(ostream& os, const Repo<T> &t){

	for(int i=0; i<t.vect.size(); i++)
		cout<<t.vect[i]<<endl;
	return os;
}

template <class T> void Repo<T>::update(T t, int pos){
	/*Desc:modifica obiectul de pe pozitia pos cu t
	* In:obiectul t, pozitia
	* Out:-
	*/
	this->vect[pos]=t;
}



#endif /* REPO_H_ */
