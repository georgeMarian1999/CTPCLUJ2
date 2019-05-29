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
    cout << "Hello, World!\n";
    Tests t;
    t.RunAllTests();
    UI U;
    U.run();
    return 0;
}
