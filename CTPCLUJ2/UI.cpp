#include "UI.h"
#include <string>
#include <Windows.h>
UI::UI(){
    
}
UI::~UI(){
    
}
int UI::decide_client()
    //functie care decide daca utilizatorul doreste sa se autentifice,sa isi creeze cont sau sa continue fara
    //logare
{
    std::cout<<"1.Autentificare"<<'\n';
    std::cout<<"2.Continuare fara autentificare"<<'\n';
    std::cout<<"3.Creare cont"<<'\n';
    std::cout<<"4.Iesire"<<'\n';
    int k;
    std::cin>>k;
    std::cout<<'\n';
    return k;

}
void UI::filtrare_nr()
{
    //filtreaza autobuzele dupa numar
    std::cout<<"Introduceti numarul autobuzului dorit: ";
        int nr;
        std::cin>>nr;
        std::cout<<'\n';
        vector<Autobuz> aux;
        aux=this->c.filterByNr(nr);
        std::cout<<aux[0].toString()<<'\n';

}
void UI::filtrare_statie()
{
    //filtreaza autobuzele care trec printr o anumita statie
    std::cout<<"Introduceti statia dorita: ";
        string statie;
        std::cin>>statie;
        std::cout<<'\n';
        vector<Autobuz> aux;
        aux=this->c.filterByStatie(statie);
        std::cout<<"Autobuzele ce trec prin statia "<<statie<<" sunt: "<<'\n';
        for(unsigned int i=0;i<aux.size();i+=1)
            {
                std::cout<<aux[i].getNumar()<<'\n';
            }

}
void afisare_pret_bilete()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        //afiseaza pretul biletelor
        std::cout<<"Preturile biletelor sunt: "<<'\n';
        std::cout<<"5RON/Bilet Zona 1(Opera, Sora, Regio) "<<'\n';
        std::cout<<"3RON/Bilet Zona 2(Cipariu, Avram, Arte, Observator)"<<'\n';
        
}
void UI::afisareoptiuninelogat(){
    //afiseaza optiunile utilizatorului nelogat
    std::cout<<"Puteti alege dintre urmatoarele: "<<'\n';
    std::cout<<"1.Filtrare autobuze dupa numar"<<'\n';
    std::cout<<"2.Afisare autobuze ce trec printr-o anumita statie"<<'\n';
    std::cout<<"3.Vizualizare preturi bilete"<<'\n';
    std::cout<<"4.Revenire"<<'\n';
}
void UI::client_nelogat()
{
    //afiseaza si apeleaza optiunile utilizatorului nelogat
    afisareoptiuninelogat();
    int optiune;
    std::cin>>optiune;
    std::cout<<'\n';
    while(optiune<4)
    {
    if(optiune==1)
    {
        afiseazanrautobuze();
        filtrare_nr();
    }
    else if(optiune==2)
    {
        afiseazanumelestatiilor();
        filtrare_statie();

    }
    else if(optiune==3)
    {
        afisare_pret_bilete();
    }
        afisareoptiuninelogat();
        std::cin>>optiune;
    }
}
void UI::situatie_cont(int pos)
{
    //afiseaza situatia contului unui client
    
    std::cout<<"Bilete din contul dumneavoastra sunt: "<<'\n';
    int zona1=0,zona2=0;
    RepoBilete zona;
    for(int i=0;i<this->c.getClienti().getClient(pos)->getBilete().getSize();i+=1)
    {
        if(this->c.getClienti().getClient(pos)->getBilete().getAll()[i].getZona()==1)
        {   
            zona1+=1;

        }
        else{
            zona2+=1;
        }

    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    std::cout<<" Zona 1: "<<zona1<<'\n';
    std::cout<<" Zona 2: "<<zona2<<'\n';
    

}
void UI::calatorie()
{
    //functie care afiseaza drumul pe care trebuie un utilizator sa il urmeze pentru a face cat mai putin
    std::cout<<"Introduceti statia de pornire: ";
    string pornire;
    std::cin>>pornire;
    std::cout<<'\n';
    std::cout<<"Introduceti statia de sosire: ";
    string sosire;
    std::cin>>sosire;
    std::cout<<'\n';
    vector<Autobuz> traseu;
    traseu=this->c.traseuDirect(pornire,sosire);
    if(traseu.size()!=0)
    {
        std::cout<<"Pentru a ajunge din statia "<<pornire<<" in statia "<<sosire<<" puteti lua autobuzul ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        std::cout<<traseu[0].getNumar();
       
        std::cout<<" ce pleaca in ... minute"<<'\n';
        std::cout<<"Introduceti numarul autobuzului dorit: ";
        int nrAuto;
        std::cin>>nrAuto;
        std::cout<<'\n';
        plata_client(nrAuto);
    }
    else{
        vector<vector<Autobuz>> rezfinal;
        vector<Statie> coborare;
        this->c.traseuIndirect(pornire,sosire,rezfinal,coborare);
        vector<Autobuz> aux;
        aux.push_back(rezfinal[0][0]);
        aux.push_back(rezfinal[0][1]);
        int k1=0,k2=1, pos;
        for(unsigned int i=0;i<rezfinal.size();i+=1)
        {
            while(aux[0]==rezfinal[i][0] && aux[1]==rezfinal[i][1])
            {
                i+=1;
            }
            aux.push_back(rezfinal[i][0]);
            aux.push_back(rezfinal[i][1]);
            pos=i;
            i=rezfinal.size();

        }
        std::cout<<"Pentru a ajunge din statia "<<pornire<<" in statia "<<sosire<<" puteti lua autbuzele: "<<'\n';
        std::cout<<"1. "<<aux[0].getNumar()<<" si sa schimbati in statia "<<coborare[0].getnume()<<" cu autobuzul "<<aux[1].getNumar()<<'\n';
        std::cout<<"2. "<<aux[2].getNumar()<<" si sa schimbati in statia "<<coborare[1].getnume()<<" cu autobuzul "<<aux[3].getNumar()<<'\n';


       

    }
    
}
void UI::afisareoptiunilogat(){
    //afiseaza optiunile unui utilizator logat
    std::cout<<"Puteti alege dintre urmatoarele: "<<'\n';
    std::cout<<"1.Filtrare autobuze dupa numar"<<'\n';
    std::cout<<"2.Afisare autobuze ce trec printr-o anumita statie"<<'\n';
    std::cout<<"3.Vizualizare preturi bilete"<<'\n';
    std::cout<<"4.Situatie cont "<<'\n';
    std::cout<<"5.Planificare calatorie"<<'\n';
    std::cout<<"6.Revenire"<<'\n';
}
void UI::afiseazanrautobuze(){
    //afiseaza toate nr autobuzelor
    cout<<"Autobuzele disponibile sunt "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    for(int i=0;i<c.getvectAutoBuz().size();i++)
    {
        cout<<c.getvectAutoBuz()[i].getNumar()<<" ";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<endl;
}
void UI::afiseazanumelestatiilor(){
    //afiseaza nr tuturor statiilor
    cout<<"Statiile disponibile sunt "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    for(int i=0;i<c.getTraseu().getGraf().size();i++)
        cout<<c.getTraseu().getGraf()[i].getinfo()<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<endl;
}
void UI::client_logat()
{
    //afiseaza si apeleaza optiunile utilizatorului logat
    std::cout<<"Va rog introduceti datele pentru logare: "<<'\n';
    std::cout<<"username: ";
    string username;
    std::cin>>username;
    std::cout<<'\n';
    string parola;
    std::cout<<"parola: ";
    std::cin>>parola;
    std::cout<<'\n';
    int pos=-1;
    for(int i=0;i<this->c.getClienti().getSize();i+=1)
        {
            Client* cc=new ClientLogat;
            cc=this->c.getClienti().getClient(i);
            if(username==cc->getUserName() && parola==cc->getParola())
                {
                    pos=i;
                    std::cout<<"Autentificarea realizata cu succes!"<<'\n';
                }
            
        }
    afisareoptiunilogat();
    int optiune;
    std::cin>>optiune;
    std::cout<<'\n';
    while(optiune<6)
    {
    if(optiune==1)
    {
        afiseazanrautobuze();
        filtrare_nr();
    }
    else if(optiune==2)
    {
        afiseazanumelestatiilor();
        filtrare_statie();

    }
    else if(optiune==3)
    {
        afisare_pret_bilete();
    }
    else if(optiune==4)
    {
        situatie_cont(pos);
    }
    else if(optiune==5)
    {
        calatorie();
    }
        afisareoptiunilogat();
        cin>>optiune;
    }
    
    

}
void UI::sign_up()
{
    //functie care permite utilizatorului sa isi creeze un cont
    std::cout<<"Va rugam introduceti datele pentru noul cont: "<<'\n';
    std::cout<<"Username: ";
    string username;
    std::cin>>username;
    std::cout<<'\n';
    std::cout<<"Parola: ";
    string parola;
    std::cin>>parola;
    std::cout<<'\n';
    std::cout<<"Introduceti datele cardului: "<<'\n';
    std::cout<<"Numar card: ";
    int nrcard,pin;
    std::cin>>nrcard;
    std::cout<<'\n';
    std::cout<<"Pin: ";
    std::cin>>pin;
    std::cout<<'\n';
    RepoBilete r;
    Card c(nrcard,pin);
    Client* newClient=new ClientLogat(c,username,parola,r);
    this->c.addClient(newClient);
    this->c.AddClient_file("DataBase1.csv");
    std::cout<<"Contul dumneavoastra a fost creat cu succes!"<<'\n';
    client_logat();
}
void UI::run()

{
    //functia principala
    t.RunAllTests();
    this->c.loadClienti("DataBase1.csv");
    this->c.loadAutobuze("BazaDateAutobuze.txt");
    c.create(c.getAutobuze());
    int optiune=decide_client();
    while(optiune<4)
    {
    if(optiune==1)
    {
        client_logat();
    }
    else if(optiune==2)
    {
        client_nelogat();
        }
       
    else if(optiune==3)
    {
        sign_up();
    }
    optiune=decide_client();
    }
}

