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
    BazaDateAutobuze B;
    B.LoadFromFile("BazaDateAutobuze.txt");
    Statie S("Observator",2);
    Ora O(11,0);
    for(int i=0;i<B.filterByTime(S, O).size();i++)
        cout<<B.filterByTime(S, O)[i].getNumar()<<" ";
    UI U;
    U.run();
    return 0;
}
