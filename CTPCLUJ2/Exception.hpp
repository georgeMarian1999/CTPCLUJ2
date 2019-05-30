//
//  Exception.hpp
//  CTPCLUJ2
//
//  Created by Marian George on 30/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Exception{
private:
    string message;
public:
    Exception(string);
    string getmessage();
};
#endif /* Exception_hpp */
