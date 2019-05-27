//
//  Tests.cpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Tests.hpp"
bool Tests::test_Ora(){
    Ora A(20,20);
    assert(A.getora()==20);
    assert(A.getminute()==20);
    Ora B=A;
    assert(B.getora()==20);
    assert(B.getminute()==20);
    assert(A==B);
    A.setora(10);
    A.setminute(10);
    assert(A.getminute()==10);
    assert(A.getora()==10);
    assert(A!=B);
    assert(A<B);
    assert(B>A);
    B.setora(10);
    assert(B>A);
    return true;
}
bool Tests::test_Statie(){
    Statie S("gara",2);
    assert(S.getnume()=="gara");
    assert(S.getzona()==2);
    S.setnume("centru");
    S.setzona(1);
    assert(S.getnume()=="centru");
    assert(S.getzona()==1);
    Statie B=S;
    assert(B.getnume()=="centru");
    assert(B.getzona()==1);
    assert(S==B);
    S.setzona(3);
    assert(S!=B);
    return true;
}
bool Tests::test_Bilet(){
	Bilet b(1, 2);
	assert(b.getPret()==1);
	assert(b.getZona()==2);
	b.setPret(3);
	b.setZona(4);
	assert(b.getPret()==3);
	assert(b.getZona()==4);
	Bilet c(3, 4);
	assert(b==c);
	Bilet e=c;
	assert(e==c);

	return true;
}

bool Tests::test_Card(){
	Card c(4140, 123);
	assert(c.getNrCard()==4140);
	assert(c.getPin()==123);
	c.setNrCard(4141);
	c.setPin(321);
	Card d(4141, 321);
	assert(c==d);
	Card e(d);
	assert(e==d);

	return true;
}

bool Tests::test_Client(){
	Card a(4140, 123);
	Client c(a);
	assert(c.getInfoCard()==a);
	Card d(4141, 321);
	c.setCard(d);
	assert(c.getInfoCard()==d);
	Client e=c;
	assert(e==c);

	return true;


}
bool Tests::test_Matrix() {
	vector<vector<Ora>> test;
	Ora A(10, 20);
	Ora B(11, 30);
	Ora C(12, 40);
	Ora A1(2, 20);
	vector<Ora> test1;
	test1.push_back(A);
	test1.push_back(B);
	test1.push_back(C);
	test1.push_back(A1);
	test.push_back(test1);
	vector<Ora> test2;
	Ora D(13, 50);
	Ora E(14, 0);
	Ora F(15, 10);
	Ora A2(1, 2);
	test2.push_back(D);
	test2.push_back(E);
	test2.push_back(F);
	test2.push_back(A2);
	test.push_back(test2);
	Ora G(16, 20);
	Ora H(18, 30);
	Ora I(19, 40);
	Ora A3(4, 8);
	vector<Ora> test3;
	test3.push_back(A);
	test3.push_back(B);
	test3.push_back(C);
	test3.push_back(A3);
	test.push_back(test3);
	Matrice Mat(test);
	assert(Mat.getnrlin() == 3);
	assert(Mat.getnrcol() == 4);
	assert(Mat(0, 1) == B);
	assert(Mat(1, 2) == F);
	assert(Mat(2, 3) == A3);
	Mat.setElem(0, 1, F);
	assert(Mat(0, 1) == F);
	Matrice Mat2 = Mat;
	assert(Mat == Mat2);
	Ora X(0, 0);
	Mat.setElem(0, 1, X);
	cout << Mat;
	cout << "DELIMITATION" << endl;
	cout << Mat2;
	assert(Mat != Mat2);
	return true;
}
bool Tests::test_Autobuz()
{
	Statie S("gara", 2);
	Statie P("tralala", 4);
	vector<Statie> v;
	v.push_back(S);
	v.push_back(P);
	vector<vector<Ora>> test;
	Ora A(10, 20);
	Ora B(11, 30);
	Ora C(12, 40);
	Ora A1(2, 20);
	vector<Ora> test1;
	test1.push_back(A);
	test1.push_back(B);
	test1.push_back(C);
	test1.push_back(A1);
	test.push_back(test1);
	vector<Ora> test2;
	Ora D(13, 50);
	Ora E(14, 0);
	Ora F(15, 10);
	Ora A2(1, 2);
	test2.push_back(D);
	test2.push_back(E);
	test2.push_back(F);
	test2.push_back(A2);
	test.push_back(test2);
	Ora G(16, 20);
	Ora H(18, 30);
	Ora I(19, 40);
	Ora A3(4, 8);
	vector<Ora> test3;
	test3.push_back(A);
	test3.push_back(B);
	test3.push_back(C);
	test3.push_back(A3);
	test.push_back(test3);
	Matrice Mat(test);
	Orar r(v, Mat);
	Autobuz a(25, r);
	assert(a.getNumar() == 25);
	assert(a.getOrar() == r);
	a.setNumar(34);
	assert(a.getNumar() == 34);
	return true;
}
void Tests::RunAllTests(){
    bool testOra=test_Ora(),testStatie=test_Statie(), testBilet=test_Bilet(), testCard=test_Card(), testClient=test_Client();
    if(testOra&&testStatie && test_Autobuz() && test_Matrix())
        cout<<"Tests ok!"<<endl;
}
