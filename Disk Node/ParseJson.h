//
// Created by nano on 17/06/17.
//

#ifndef SERVER_PARSEJSON_H
#define SERVER_PARSEJSON_H

#include <iostream>
#include "Create.h"
#include "Drop.h"
#include "Insert.h"
#include "Selectall.h"
#include "Huff.h"
#include "Clientapp.h"

using namespace std;

string Stats[50];
string ParseJson(string Json){
    int inic=0;
    int leyendo = 0;
    int ind=0;
    for(int i=0; i<(Json.length());i++) {

        if(Json[i] == ':' && leyendo==0){
            inic = i+3;
            leyendo=1;
        }
        if(Json[i] == '}' && leyendo==1){
            string temp = Json.substr(inic,i-inic-2);
            Stats[ind] = temp;
            cont+=1;
            ind++;
            leyendo=0;
        }
        if (Json[i] == ','  && leyendo==1){
            string temp = Json.substr(inic,i-inic-1);
            Stats[ind] = temp;
            cont+=1;
            ind++;
            leyendo=0;
        }


    }
    //cout<<Stats[0]<<endl;
    string val;
    string Manager;
    char str[1024];
    if(Stats[0]=="CREATE TABLE"){
        for (int i = 2; i < cont ; ++i) {
            Create(Stats[1],Stats[i]);
        }
        Manager="G,"+ Huff(Stats[1]);
    }else if(Stats[0]=="DROP TABLE"){
        Drop(Stats[1]);
        Manager="D,"+ Huff(Stats[1]);
    }else if(Stats[0]=="INSERT INTO"){
        Insert(Stats[1],Stats,cont);
        Manager="A";
    }else if(Stats[0]=="SELECT"){
        if(Stats[1]=="ALL"){
            val=Selectall(Stats[2]);
        }
        Manager="A";
    }
    //Client("192.168.100.7",8082,strcpy(str,Manager.c_str()));
    return val;
}

#endif //SERVER_PARSEJSON_H
