//
//  Tests.hpp
//  CTPCluj
//
//  Created by Marian George on 25/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Tests_hpp
#define Tests_hpp

#include <stdio.h>
#include "Orar.hpp"
#include "Statie.hpp"
#include "Ora.hpp"
#include "Bilet.h"
#include "Card.h"
#include "Client.h"
#include "Autobuz.h"
#include "ClientLogat.hpp"
#include "BazaDateAuto.hpp"
#include "BazaDateClienti.h"
#include "Ctrl.hpp"
#include "Nod.hpp"
#include "Harta.hpp"
using namespace std;
class Tests{
public:
    bool test_Ora();
    bool test_Statie();
    bool test_Orar();
	bool test_Matrix();
    bool test_Bilet();
    bool test_Card();
    bool test_Client();
	bool test_Autobuz();
	bool test_Clientlogat();
	bool test_BazaDateClienti();
	bool test_BazaDateAutobuze();
    bool test_Ctrl();
    bool test_Nod();
    bool test_Harta();
    void RunAllTests();
};
#endif /* Tests_hpp */
