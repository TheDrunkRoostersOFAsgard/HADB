//
// Created by gerardo on 15/06/17.
//

#ifndef JSON_JSONCREATOR_H
#define JSON_JSONCREATOR_H

#include <iostream>
#include <json/json.h>
#include <string.h>
using namespace std;

//"CREATE TABLE ESTUDIANTES (NOMBRE STRING, ID INT)"

void Createjson(string query){
    json_object * jobj = json_object_new_object();
    int  inic = 13;
    int ind = 1;
    int NoC = 1;
    json_object *jstring = json_object_new_string("CREATE TABLE");
    json_object_object_add(jobj,"Instruction", jstring);
    for (int i = inic; i < query.length() - 1; ++i) {
        if (query[i] == ' '){
            json_object *jstring1 = json_object_new_string(query.substr(inic,i-inic).c_str());
            json_object_object_add(jobj,"Table", jstring1);
            inic=i+2;
            break;
        }
    }
    for (int j = inic; j < query.length(); ++j) {
        if (query[j]==' '){
            json_object *jstring1 = json_object_new_string(query.substr(inic,j-inic).c_str());
            string Columna = "Columna" + to_string(NoC);
            json_object_object_add(jobj, Columna.c_str(), jstring1);
            NoC++;
            inic=j+1;
        }
        if (query[j]==','){
            j+=1;
            inic=j+1;
        }
    }
    string temp;
    char str[1024];
    temp=json_object_to_json_string(jobj);
    Client("192.168.100.9",8081,strcpy(str, temp.c_str()));
}

//"DROP TABLE DEPTO"
void Dropjson(string query){
    json_object * jobj = json_object_new_object();
    int  inic = 11;
    int ind = 1;
    int NoC = 1;
    json_object *jstring = json_object_new_string("DROP TABLE");
    json_object_object_add(jobj,"Instruction", jstring);

    for (int i = inic; i < query.length() ; ++i) {
        if (i == query.length()-1){
            json_object *jstring1 = json_object_new_string(query.substr(inic,i-inic+1).c_str());
            json_object_object_add(jobj,"Table", jstring1);
            break;
        }
    }
    string temp;
    char str[1024];
    temp=json_object_to_json_string(jobj);
    Client("192.168.100.9",8081,strcpy(str, temp.c_str()));
}

//"INSERT INTO ESTUDIANTES VALUES (jUAN, 2016253868)"
void Insertjson(string query){
    json_object * jobj = json_object_new_object();
    int  inic = 12;
    int ind = 1;
    int NoC = 1;
    json_object *jstring = json_object_new_string("INSERT INTO");
    json_object_object_add(jobj,"Instruction", jstring);
    for (int i = inic; i < query.length() - 1; ++i) {
        if (query[i] == ' '){
            json_object *jstring1 = json_object_new_string(query.substr(inic,i-inic).c_str());
            json_object_object_add(jobj,"Table", jstring1);
            inic=i+9;
            break;
        }
    }
    for (int j = inic; j < query.length(); ++j) {
        if (query[j]==','){
            json_object *jstring1 = json_object_new_string(query.substr(inic+1,j-inic).c_str());
            string Columna = "Columna" + to_string(NoC);
            json_object_object_add(jobj, Columna.c_str(), jstring1);
            NoC++;
            inic=j+2;
        }
        if (j == query.length()-1){
            json_object *jstring1 = json_object_new_string(query.substr(inic,j-inic).c_str());
            string Columna = "Columna" + to_string(NoC);
            json_object_object_add(jobj, Columna.c_str(), jstring1);
            NoC++;
        }
    }

    string temp;
    char str[1024];
    temp=json_object_to_json_string(jobj);
    Client("192.168.100.9",8081,strcpy(str, temp.c_str()));
}

//"SELECT * FROM orders"
void Selectjson(string query){
    json_object * jobj = json_object_new_object();
    int  inic = 6;
    int ind = 1;
    int NoC = 1;
    json_object *jstring = json_object_new_string("SELECT");
    json_object_object_add(jobj,"Instruction", jstring);
    for (int i = inic; i < query.length() ; ++i) {
        if(query[i]==' ') {
            if (query[i+1] == '*') {
                json_object *jstring2 = json_object_new_string("ALL");
                string Columna = "Columna" + to_string(NoC);
                json_object_object_add(jobj, Columna.c_str(), jstring2);
                inic = i+7;
                break;
            } else{
                inic = i+1;
                break;
            }
        }
    }
    for (int k = inic; k < query.length() - 1; ++k) {
        if(query[k]==',') {
            json_object *jstring1 = json_object_new_string(query.substr(inic,k-inic).c_str());
            string Columna = "Columna" + to_string(NoC);
            json_object_object_add(jobj, Columna.c_str(), jstring1);
            NoC++;
            inic=k+1;
        }
        else if (query[k] == ' '){
            json_object *jstring1 = json_object_new_string(query.substr(inic,k-inic).c_str());
            string Columna = "Columna" + to_string(NoC);
            json_object_object_add(jobj, Columna.c_str(), jstring1);
            inic = k+6;
            break;
        }
    }
    json_object *jstring1 = json_object_new_string("FROM");
    json_object_object_add(jobj,"FROM", jstring1);
    for (int j = inic; j < query.length(); ++j) {
        if(j == query.length()-1) {
            json_object *jstring1 = json_object_new_string(query.substr(inic,j-inic+1).c_str());
            json_object_object_add(jobj,"Table", jstring1);
            inic=j+9;
        }
    }

    string temp;
    char str[1024];
    temp=json_object_to_json_string(jobj);
    Client("192.168.100.9",8081,strcpy(str, temp.c_str()));
}

#endif //JSON_JSONCREATOR_H
