//
//  main.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 27/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include <iostream>
#include "Tests.hpp"
#include "UI.h"
int main(int argc, const char * argv[]) {
    //UI U;
    //U.run();
    BazaDateClienti B;
    B.LoadFromFile("DataBase1.csv");
    B.AddClient_File("testout.csv");
    BazaDateAutobuze A;
    A.LoadFromFile("BazaDateAutobuze.txt");
    Statie S("Observator",2);
    Ora H(11,0);
    for(int i=0;i<A.filterByTime(S, H).size();i++)
        cout<<A.filterByTime(S, H)[i]<<" ";
    return 0;
}
