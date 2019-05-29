#ifndef UI_H
#define UI_H

#include "Ctrl.hpp"
#include "Tests.hpp"
class UI{
private:
    Ctrl c;
    Tests t;
public:
    UI()
    {

    }
    ~UI()
    {

    }
    void run();
    bool decide_client();
    void client_logat();
    void client_nelogat();


}




#endif