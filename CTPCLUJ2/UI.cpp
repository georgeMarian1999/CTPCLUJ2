#include "UI.h"
#include <string>
//#include <Windows.h>
UI::UI(){
    
}
UI::~UI(){
    
}
string UI::citestestatiepornire(){
    std::cout<<"Introduceti statia de pornire: ";
    string pornire;
    std::cin>>pornire;
    std::cout<<'\n';
    if(c.getAutobuze().esteStatie(pornire)==false)
        throw Exception("Statia nu se afla in baza de date.Va rugam incercati din nou\n");
    return pornire;
}
string UI::citestestatiesosire(){
    std::cout<<"Introduceti statia de sosire: ";
    string sosire;
    std::cin>>sosire;
    std::cout<<'\n';
    if(c.getAutobuze().esteStatie(sosire)==false)
        throw Exception("Statia nu se afla in baza de date.Va rugam incercati din nou\n");
    return sosire;
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
Ora UI::citireora(){
    string s;
    cin>>s;
    int ora=(s[0]-'0')*10+(s[1]-'0');
    int min=(s[3]-'0')*10+(s[4]-'0');
    Ora O(ora,min);
    return O;
}
void UI::filtrare_nr()
{
    //filtreaza autobuzele dupa numar
    bool ok=false;
    while(ok==false)
        try {
            std::cout<<"Introduceti numarul autobuzului dorit: ";
            int nr;
            std::cin>>nr;
            std::cout<<'\n';
            vector<Autobuz> aux;
            aux=this->c.filterByNr(nr);
            std::cout<<aux[0].toString()<<'\n';
            ok=true;
        } catch (Exception &exc) {
            cout<<exc.getmessage();
        }
}
void UI::filtrare_statie()
{
    //filtreaza autobuzele care trec printr o anumita statie
        bool ok=false;
        while(ok==false)
            try {
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
                ok=true;
            } catch (Exception &exc) {
                cout<<exc.getmessage();
            }

}
void afisare_pret_bilete()
{
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
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
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    std::cout<<" Zona 1: "<<zona1<<'\n';
    std::cout<<" Zona 2: "<<zona2<<'\n';
    

}
void plata_client(BazaDateAutobuze a, Client* client)
{
    int zona=99;
    int nr=0;
    for(unsigned int i=0;i<a.getall().size();i+=1)
    {
        for(unsigned int j=0;j<a.getall()[i].getOrar().getStatii().size();j+=1)
        {
            if(zona>a[i].getall().getOrar().getStatii()[j].getzona())
                zona=a[i].getall().getOrar().getStatii()[j].getzona();
        }
        nr+=1;
    }
    if(client->getBilete().getSize()!=0)
    {
        for(unsigned int i=0;i<client->getBilete().getAll().size();i+=1)
        {
            if(client->getBilete().getAll()[i].getZona()==zona)
            {
                nr-=1;
            }
        }
        if(nr)
        {
            std::cout<<"Pentru calatoria aleasa mai aveti nevoie de "<<nr<<" bilete pentru zona "<<zona<<'\n';
            std::cout<<"1.Initializare plata"<<'\n';
            int k;
            std::cin>>k;
            if(k==1)
            {
                std::cout<<"Introduceti numar card: ";
                int nrcard; 
                int pin;
                std::cin>>nrcard;
                std::cout<<'\n';
                std::cout<<"Introduceti pin-ul: ";
                std::cin>>pin;
                if(client->getInfoCard().getNrCard()==nrcard && client->getInfoCard().getPin()==pin)
                {
                    int hopa;
                    if(zona==1){hopa=5;}
                    else{hopa=3;}
                    for(int l=0;l<nr;l+=1)
                    {client->getBilete().addElement(Bilet(hopa,zona));}
                    std::cout<<"Plata a fost realizata cu succes!"<<'\n';
                    std::cout<<"Biletele dumneavoastra curente sunt: "<<'\n';
                    for(unsigned int j=0;j<client->getBilete().getSize();j+=1)
                    {
                        std::cout<<client->getBilete().getAll()[j].toString()<<'\n';
                    }
                    
                }
                


            }
            else{
                std::cout<<"Biletele din contul dumneavoastra vor fi folosite pentru calatoria curenta"<<'\n';
            }
        }
    }
    else{
            std::cout<<"Pentru calatoria aleasa aveti nevoie de "<<nr<<" bilete pentru zona "<<zona<<'\n';
            std::cout<<"1.Initializare plata"<<'\n';
            int k;
            std::cin>>k;
            if(k==1)
            {
                std::cout<<"Introduceti numar card: ";
                int nrcard; 
                int pin;
                std::cin>>nrcard;
                std::cout<<'\n';
                std::cout<<"Introduceti pin-ul: ";
                std::cin>>pin;
                if(client->getInfoCard().getNrCard()==nrcard && client->getInfoCard().getPin()==pin)
                {
                    int hopa;
                    if(zona==1){hopa=5;}
                    else{hopa=3;}

                    for(int l=0;l<nr;l+=1)
                    {client->getBilete().addElement(Bilet(hopa,zona));}
                    std::cout<<"Plata a fost realizata cu succes!"<<'\n';
                    std::cout<<"Bilete dumneavoastra curente sunt: "<<'\n';
                    for(unsigned int j=0;j<client->getBilete().getSize();j+=1)
                    {
                        std::cout<<client->getBilete().getAll()[j].toString()<<'\n';
                    }
                }

    }
    }
}
void UI::calatorie(int pos)
{
    //functie care afiseaza drumul pe care trebuie un utilizator sa il urmeze pentru a face cat mai putin
    bool ok=true;
    string pornire;
    while(ok)
        try {
            pornire=citestestatiepornire();
            ok=false;
            
        } catch (Exception &exc) {
            cout<<exc.getmessage();
        }
    ok=true;
    string sosire;
    while (ok)
        try {
            sosire=citestestatiesosire();
            ok=false;
        } catch (Exception &exc) {
            cout<<exc.getmessage();
        }
    
    BazaDateAutobuze traseu(this->c.traseuDirect(pornire,sosire));
    cout<<"Doriti sa plecati acum sau mai tarziu?"<<endl;
    string decizie;
    cin>>decizie;
    Ora O(10,10);
    /*if(decizie.find("Acum")==0||decizie.find("acum")==0)
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int hour=aTime->tm_hour;
        int min=aTime->tm_min;
        O.setora(hour);
        O.setminute(min);
    }
    else{
        std::cout<<"Introducet ora dorita pentru calatorie:"<<'\n';
        std::cout<<"Ora: ";
        O=citireora();
        }*/
    Statie s;
    s.setnume(pornire);
    cout<<pornire;
    s.setzona(traseu.zona(pornire));
    cout<<s.getzona()<<endl;
    traseu=traseu.filterByTime(s,O);
    if(traseu.getall().size()!=0)
    {
        std::cout<<"Pentru a ajunge din statia "<<pornire<<" in statia "<<sosire<<" puteti lua: "<<'\n';
        for(unsigned int i=0;i<traseu.getall().size();i++)
        {
         
        
        std::cout<<i+1<<". "<<traseu.getall()[i].getNumar()<<'\n';

        }
        std::cout<<"Va rugam sa introduceti traseul dorit: ";
        int nrTraseu;
        std::cin>>nrTraseu;
        std::cout<<'\n';
        plata_client(traseu,this->c.getClienti().getClient(pos));
        
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
        std::cout<<"Va rugam sa alegeti traseul dorit: ";
        int l;
        std::cin>>l;
        std::cout<<'\n';
        BazaDateAutobuze alex;
        if(l==1)
        {
            alex.addElement(aux[0]);
            alex.addElement(aux[1]);
        }
        else{
            alex.addElement(aux[2]);
            alex.addElement(aux[3]);
        }
        plata_client(alex,this->c.getClienti().getClient(pos));
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
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    for(int i=0;i<c.getvectAutoBuz().size();i++)
    {
        cout<<c.getvectAutoBuz()[i].getNumar()<<" ";
    }
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<endl;
}
void UI::afiseazanumelestatiilor(){
    //afiseaza nr tuturor statiilor
    cout<<"Statiile disponibile sunt "<<endl;
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    for(int i=0;i<c.getTraseu().getGraf().size();i++)
        cout<<c.getTraseu().getGraf()[i].getinfo()<<endl;
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
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
    if(pos!=-1){
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
    if(optiune==2)
    {
        afiseazanumelestatiilor();
        filtrare_statie();

    }
    if(optiune==3)
    {
        afisare_pret_bilete();
    }
    if(optiune==4)
    {
        situatie_cont(pos);
    }
    if(optiune==5)
    {
        calatorie(pos);
    }
        afisareoptiunilogat();
        cin>>optiune;
    }
    }
    else{
        client_logat();
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
    int nrcard,pin;
    std::cout<<"Introduceti datele cardului: "<<'\n';
    std::cout<<"Numar card: ";
    std::cin>>nrcard;
    std::cout<<'\n';
    RepoBilete r;
    Card car;
    car.setNrCard(nrcard);
    bool ok=true;
    while(ok)
        try{
            std::cout<<"Pin: ";
            std::cin>>pin;
            std::cout<<'\n';
            car.setPin(pin);
            ok=false;
        }
    catch (Exception &exc){
        cout<<exc.getmessage()<<endl;
    }
    Client* newClient=new ClientLogat(car,username,parola,r);
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
    while(optiune!=4)
    {
        try{
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
        catch (Exception &exc){
            cout<<exc.getmessage();
        }
    }
}

