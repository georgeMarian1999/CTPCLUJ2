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
	test3.push_back(G);
	test3.push_back(H);
	test3.push_back(I);
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
	assert(Mat != Mat2);
	return true;
}
bool Tests::test_Orar(){
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
    test3.push_back(G);
    test3.push_back(H);
    test3.push_back(I);
    test3.push_back(A3);
    test.push_back(test3);
    Matrice Mat(test);
    Statie S("gara", 2);
    Statie P("tralala", 4);
    Statie X("sora",3);
    Statie J("centru",1);
    vector<Statie> v;
    v.push_back(S);
    v.push_back(P);
    v.push_back(X);
    v.push_back(J);
    Orar U(v,Mat);
    for(int i=0;i<U.getStatii().size();i++)
        assert(U.getStatii()[i]==v[i]);
    assert(U.getTimpi()==Mat);
    return true;
}
bool Tests::test_Autobuz()
{
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
    test3.push_back(G);
    test3.push_back(H);
    test3.push_back(I);
    test3.push_back(A3);
    test.push_back(test3);
    Matrice Mat(test);
    Statie S("gara", 2);
    Statie P("tralala", 4);
    Statie X("sora",3);
    Statie J("centru",1);
    vector<Statie> v;
    v.push_back(S);
    v.push_back(P);
    v.push_back(X);
    v.push_back(J);
    Orar U(v,Mat);
	Autobuz a(25, U);
	assert(a.getNumar() == 25);
    assert(a.getOrar()==U);
    vector<Ora> Aux;
    Aux.push_back(A);
    Aux.push_back(D);
    Aux.push_back(G);
    for(int i=0;i<a.getOrar().getTimpiStatie(S).size();i++)
        assert(a.getOrar().getTimpiStatie(S)[i]==Aux[i]);
	a.setNumar(34);
	assert(a.getNumar() == 34);
    BazaDateAutobuze BazaDate;
    BazaDate.LoadFromFile("BazaDateAutobuze.txt");
    cout<<BazaDate.getall()[0].nr_Statii("Memo", "Regio")<<endl;
    //assert(BazaDate.getall()[0].nr_Statii("Memo", "Arte")==4);
	return true;
}
bool Tests::test_Clientlogat(){
	Card a(4140, 123);
	Bilet b(1, 2);
	Bilet c(3, 4);
	vector<Bilet> v;
	v.push_back(b);
	v.push_back(c);
	RepoBilete r(v);
	ClientLogat client(a, "Ana", "1234", r);
	assert(client.getInfoCard()==a);
	assert(client.getUserName()=="Ana");
	assert(client.getParola()=="1234");
	assert(client.getBilete()==r);
	client.setParola("11");
	assert(client.getParola()=="11");
	ClientLogat x=client;
	assert(x==client);
	return true;
}
bool Tests::test_BazaDateClienti(){
	    Card a(4140, 123);
		Bilet b(1, 2);
		Bilet c(3, 4);
		vector<Bilet> v;
		v.push_back(b);
		v.push_back(c);
		RepoBilete r(v);
		Client* client1=new ClientLogat(a, "Ana", "1234", r);
		Card a2(1234, 101);
		Client* client2=new Client(a2);
        BazaDateClienti baza;
		baza.addClient(client1);
		assert(baza.getAll()[0]==client1);
		baza.addClient(client2);
		assert(baza.getAll()[1]==client2);
		baza.update(client2, 0);
		assert(baza.getAll()[0]==client2);
        BazaDateClienti baza2=baza;
        assert(baza==baza2);
        return true;
}
bool Tests::test_BazaDateAutobuze(){
	    Statie S("gara", 2);
		Statie P("tralala", 4);
        Statie X("sora",3);
        Statie J("centru",1);
		vector<Statie> v;
		v.push_back(S);
		v.push_back(P);
        v.push_back(X);
        v.push_back(J);
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
		BazaDateAutobuze baza;
		baza.addElement(a);
        assert(baza.getall()[0]==a);
        return true;
}
bool Tests::test_Ctrl(){
    Card a(4140, 123);
    Bilet b(1, 2);
    Bilet c(3, 4);
    vector<Bilet> v;
    v.push_back(b);
    v.push_back(c);
    RepoBilete r(v);
    Client* client1=new ClientLogat(a, "Ana", "1234", r);
    Card a2(1234, 101);
    Client* client2=new Client(a2);
    BazaDateClienti baza;
    baza.addClient(client1);
    baza.addClient(client2);
    Statie S("gara", 2);
    Statie P("tralala", 4);
    Statie X("sora",3);
    Statie J("centru",1);
    vector<Statie> Statii;
    Statii.push_back(S);
    Statii.push_back(P);
    Statii.push_back(X);
    Statii.push_back(J);
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
    Orar orer(Statii, Mat);
    Autobuz autob(25, orer);
    BazaDateAutobuze baza2;
    baza2.addElement(autob);
    Ctrl Controler(baza,baza2);
    assert(Controler.getClienti()==baza);
    assert(Controler.getAutobuze()==baza2);
    BazaDateClienti BazaGoala;
    BazaDateAutobuze bazagoala;
    Controler.setbazaclienti(BazaGoala);
    Controler.setbazaauto(bazagoala);
    assert(Controler.getClienti()==BazaGoala);
    assert(Controler.getAutobuze()==bazagoala);
    return true;
}
bool Tests::test_Nod(){
    vector<string> v;
    for(int i=0;i<4;i++)
        v.push_back("test");
    Nod N("testinfo",v);
    assert(N.getinfo()=="testinfo");
    for(int i=0;i<4;i++)
        assert(v[i]==N.getvecini()[i]);
    N.setinfo("INFO");
    vector<string> v2;
    v2.push_back("TEST");
    v2.push_back("TEsT");
    N.setvecini(v2);
    assert(N.getinfo()=="INFO");
    for(int i=0;i<v2.size();i++)
        assert(v2[i]==N.getvecini()[i]);
    Nod M=N;
    assert(N==M);
    N.setinfo("nimic");
    assert(N!=M);
    return true;
}
bool Tests::test_Harta(){
    vector<string> v1;
    v1.push_back("info");
    v1.push_back("nod");
    Nod N1("test",v1);
    vector<string> v2;
    v2.push_back("test");
    v2.push_back("nod");
    v2.push_back("test2");
    Nod N2("info",v2);
    vector<string> v3;
    v3.push_back("info");
    v3.push_back("info2");
    v3.push_back("test");
    Nod N3("nod",v3);
    vector<string> v4;
    v4.push_back("nod");
    Nod N4("info2",v4);
    vector<string> v5;
    v5.push_back("info");
    Nod N5("test2",v5);
    vector<Nod> Graf;
    Graf.push_back(N1);
    Graf.push_back(N2);
    Graf.push_back(N3);
    Graf.push_back(N4);
    Graf.push_back(N5);
    Harta H(Graf);
    for(int i=0;i<H.getGraf().size();i++)
        assert(H.getGraf()[i]==Graf[i]);
    for(int i=0;i<v2.size();i++)
        assert(H.getvecini("info")[i]==v2[i]);
    for(int i=0;i<v1.size();i++)
        assert(H.getvecini("test")[i]==v1[i]);
    Harta H2=H;
    assert(H==H2);
    return true;
}
bool Tests::test_Filtre(){
	BazaDateAutobuze baza;
	baza.LoadFromFile("BazaDateAutobuze.txt");
	vector<Autobuz> aux;
	aux.push_back(baza.getall()[0]);
    assert(baza.filterByNr(24)[0]==aux[0]);
	vector<Autobuz> aux2;
	aux2.push_back(baza.getall()[0]);
	aux2.push_back(baza.getall()[3]);
    assert(baza.filterByStatie("Memo")[0]==baza.getall()[0]);
    assert(baza.filterByStatie("Memo")[1]==baza.getall()[3]);
	return true;
}
bool Tests::test_Exception(){
    Exception E("Test");
    assert(E.getmessage()=="Test");
    return true;
}
void Tests::RunAllTests(){

   


    if(test_Ora()&&test_Statie()&&test_Matrix()&&test_Client()&&test_Card()&&test_Bilet()&&test_Orar()&&test_Autobuz()&& test_Clientlogat()&& test_BazaDateClienti()&&test_BazaDateAutobuze()&&test_Ctrl()&&test_Nod()&&test_Harta()&& test_Filtre()&&test_Exception())
        cout<<"Tests ok!"<<endl;
}
