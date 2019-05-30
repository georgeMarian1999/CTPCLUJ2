#ifndef UI_H
#define UI_H

#include "Ctrl.hpp"
#include "Tests.hpp"
class UI{
private:
    Ctrl c;
    Tests t;
public:
    UI();
    ~UI();
    void run();
    bool decide_client();
    void client_logat();
    void client_nelogat( );
    void filtrare_nr();
    void filtrare_statie();
    void situatie_cont(int);
    void calatorie();
};




#endif
