//
//  Exception.cpp
//  CTPCLUJ2
//
//  Created by Marian George on 30/05/2019.
//  Copyright © 2019 Marian George. All rights reserved.
//

#include "Exception.hpp"
Exception::Exception(string m){
    message=m;
}
string Exception::getmessage(){
    return message;
}
