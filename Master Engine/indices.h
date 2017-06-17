//
// Created by juander1012 on 6/17/17.
//

#ifndef SERVER_INDICES_H
#define SERVER_INDICES_H
#include "Btree.h"
#include <iostream>


using namespace std;
string temp;

 string indices (string peticion){
    for (int i = 0; i < peticion.length(); ++i) {
        if (peticion[i]==','){
            temp = peticion.substr(i+1,peticion.length());
            //cout<<temp<<endl;
        }
    }
     return temp;
}
#endif //SERVER_INDICES_H
