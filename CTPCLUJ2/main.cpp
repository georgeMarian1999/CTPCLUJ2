//
//  main.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 27/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include <iostream>
#include "Tests.hpp"
int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    Tests t;
    t.RunAllTests();
    BazaDateAutobuze b;
    b.LoadFromFile("BazaDateAutobuze.txt");
    cout<<b.toString();
    return 0;
}
