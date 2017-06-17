//
// Created by nano on 15/06/17.
//
#include <iostream>
#include <fstream>
#include <cstdlib>

void Insert(string Tabla, string Stat [], int cont){

    string direc= "Tablas/";
    string direcc=direc+Tabla;
    string url=direcc+"/";

    ifstream archivo_entrada(url+"info.txt");;
    string linea;
    getline(archivo_entrada, linea);

    //llenar la cola con info
    string cola[50];
    int inic=0;
    int ind=0;
    for (int j = 0; j <linea.length() ; ++j) {
        if(linea[j]==','){
            string temp = linea.substr(inic,j-inic);
            cola[ind]= temp;
            ind++;
            inic = j+1;
        }
    }

    string tempo="";
    for (int i = 3; i <cont; ++i) {
        tempo=cola[i-2];
        string direccion=url+tempo;
        ofstream archivo;
        archivo.open(direccion+ ".txt", ios::app);
        archivo << Stat[2]+"-"+Stat[i]+",";
        archivo.close();
    }



    string tempi="";
    tempi=cola[0];
    string direccio=url+tempi;
    ofstream archivo;
    archivo.open(direccio+ ".txt", ios::app);
    archivo << Stat[3]+"-"+Stat[3]+",";
    archivo.close();



}