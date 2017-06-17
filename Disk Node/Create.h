//
// Created by nano on 15/06/17.
//
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


using namespace std;

int Create(string Name, string Columna) {
    string ruta = "Tablas/";
    string carpeta= Name;
    string ruta_absoluta= ruta+Name;

    string p=ruta_absoluta+"/";

    struct stat st = {0};

    if (stat(ruta_absoluta.c_str(), &st) == -1) {
        mkdir(ruta_absoluta.c_str(), 0700);
    }

    ofstream ficheroSalida(p+ Columna+ ".txt");

    ofstream archivo;
    archivo.open(p+"info.txt",ios::app);
    archivo<<Columna+",";
    archivo.close();


    return 0;

}