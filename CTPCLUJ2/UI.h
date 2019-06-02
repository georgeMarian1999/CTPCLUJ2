#ifndef UI_H
#define UI_H

#include "Ctrl.hpp"
#include "Tests.hpp"
#include <time.h>
class UI{
private:
    Ctrl c;
    Tests t;
public:
    UI();
    ~UI();
    void run();
    int decide_client();
    void client_logat();
    void client_nelogat( );
    void filtrare_nr();
    void filtrare_statie();
    void situatie_cont(int);
    void calatorie();
    void afisareoptiuninelogat();
    void afisareoptiunilogat();
    void afiseazanrautobuze();
    void afiseazanumelestatiilor();
    void sign_up();
    void plata_client();
    string citestestatiepornire();
    string citestestatiesosire();
    Ora citireora();
};




#endif
