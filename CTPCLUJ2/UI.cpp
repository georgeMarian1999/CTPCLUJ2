#include "UI.h"
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
        std::cout<<"Introduceti numarul autobuzului dorit: ";
        int nr;
        std::cin>>nr;
        std::cout<<'\n';
        vector<Autobuz> aux;
        aux=this->c.filterByNr(nr);
        std::cout<<"Autobuzul "<<nr<<" are urmatorul orar: "<<'\n';
        std::cout<<aux[0].toString()<<'\n';

        
    }
    else if(optiune==2)
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
    else if(optiune==3)
    {
        std::cout<<"Preturile biletelor sunt: "<<'\n';
        std::cout<<"5RON/Bilet Zona 1( Opera, Sora, Regio) "<<'\n';
        std::cout<<"3/RON/Bilet Zona 2(Cipariu, Avram, Arte, Observator)"<<'\n';
        
    }
}
void UI::run()

{   this->c.loadClienti("DataBase1.csv");
    this->c.loadAutobuze("BazaDateAutobuze.txt");
    cout<<c.getAutobuze().toString();
    cout<<c.getClienti().toString();
    if(decide_client())
    {
        //client_logat();

    }
    else {
        client_nelogat();

    }
}
