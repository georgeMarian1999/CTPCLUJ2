#include "UI.h"
#include <string>
UI::UI(){
    
}
UI::~UI(){
    
}
bool UI::decide_client()
{
    std::cout<<"1.Autentificare"<<'\n';
    std::cout<<"2.Continuare fara autentificare"<<'\n';
    int k;
    std::cin>>k;
    std::cout<<'\n';
    return(k==1);

}
void UI::filtrare_nr()
{
    std::cout<<"Introduceti numarul autobuzului dorit: ";
        int nr;
        std::cin>>nr;
        std::cout<<'\n';
        vector<Autobuz> aux;
        aux=this->c.filterByNr(nr);
        std::cout<<"Autobuzul "<<nr<<" are urmatorul orar: "<<'\n';
        std::cout<<aux[0].toString()<<'\n';

}
void UI::filtrare_statie()
{
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
        std::cout<<"Preturile biletelor sunt: "<<'\n';
        std::cout<<"5RON/Bilet Zona 1( Opera, Sora, Regio) "<<'\n';
        std::cout<<"3/RON/Bilet Zona 2(Cipariu, Avram, Arte, Observator)"<<'\n';
}
void UI::client_nelogat()
{
    
    std::cout<<"Puteti alege dintre urmatoarele: "<<'\n';
    std::cout<<"1.Filtrare autobuze dupa numar"<<'\n';
    std::cout<<"2.Afisare autobuze ce trec printr-o anumita statie"<<'\n';
    std::cout<<"3.Vizualizare preturi bilete"<<'\n';
    
    int optiune;
    std::cin>>optiune;
    std::cout<<'\n';
    
    if(optiune==1)
    {  
        filtrare_nr();
    }
    else if(optiune==2)
    {
        filtrare_statie();

    }
    else if(optiune==3)
    {
        afisare_pret_bilete();
    }
}
void UI::situatie_cont(int pos)
{
    std::cout<<"Bilete din contul dumneavoastra sunt: "<<'\n';
    int zona1=0,zona2=0;
    RepoBilete zona2;
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
    std::cout<<"Zona 1: "<<zona1<<'\n';
    std::cout<<"Zona 2: "<<zona2<<'\n';

}
void UI::client_logat()
{
    std::cout<<"Va rog introduceti datele pentru logare: "<<'\n';
    std::cout<<"username: ";
    string username;
    std::cin>>username;
    std::cout<<'\n';
    string parola;
    std::cout<<"parola: ";
    std::cin>>parola;
    std::cout<<'\n';
    int pos;
    for(int i=0;i<this->c.getClienti().getSize();i+=1)
        {
            ClientLogat* cc=new ClientLogat;
            cc=this->c.getClienti().getClient(i);
            if(username==cc->getUserName() && parola==cc->getParola())
                {
                    pos=i;
                    std::cout<<"Autentificarea realizata cu succes!"<<'\n';
                }
            
        }
    std::cout<<"Puteti alege dintre urmatoarele: "<<'\n';
    std::cout<<"1.Filtrare autobuze dupa numar"<<'\n';
    std::cout<<"2.Afisare autobuze ce trec printr-o anumita statie"<<'\n';
    std::cout<<"3.Vizualizare preturi bilete"<<'\n';
    std::cout<<"4.Situatie cont "<<'\n';
    
    int optiune;
    std::cin>>optiune;
    std::cout<<'\n';
    
    if(optiune==1)
    {  
        filtrare_nr();
    }
    else if(optiune==2)
    {
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
    
    

}
void UI::run()

{   this->c.loadClienti("DataBase1.csv");
    this->c.loadAutobuze("BazaDateAutobuze.txt");
    cout<<c.getAutobuze().toString();
    cout<<c.getClienti().toString();
    if(decide_client())
    {
        client_logat();

    }
    else {
        client_nelogat();

    }
}
