//
// Created by nano on 16/06/17.
//

#include <iostream>

using namespace std;

string vect[50];
int cont=0;

int contfil(string tabla, string colum){
    int contador=0;
    string direc= "Tablas/";
    string direcc=direc+tabla;
    string url=direcc+"/";
    ifstream archivo_entrada(url+colum+".txt");;
    string linita;
    getline(archivo_entrada, linita);


    for (int i = 0; i < linita.length(); ++i) {
        if(linita[i]==','){
            contador++;
        }
    }

    return contador;
}



void camb_tovec(string linea){

    int indguion=0;
    int ind=0;
    for (int j = 0; j <linea.length() ; ++j){
        if(linea[j]=='-'){
            indguion=j+1;
        }
        if(linea[j]==',' ){
            string temp = linea.substr(indguion,j-indguion);
            vect[ind]=temp;
            ind+=1;
            indguion=j+1;
        }
    }
    //cout<<vect[0]<<endl;
}

void camb_tovec2(string linea){

    int inic=0;
    int ind=0;
    for (int j = 0; j <linea.length() ; ++j){
        if(linea[j]==',' ){
            string temp = linea.substr(inic,j-inic);
            vect[ind]=temp;
            inic=j+1;
            ind++;
        }
    }
    //cout<<vect[2]<<endl;
}


string Selectall(string tabla){
    for (int m = 0; m < 50; ++m) {
        vect[m] = "";
    }
    //abrir info de la tabla y guardar la linea en un string
    string direc= "Tablas/";
    string direcc=direc+tabla;
    string url=direcc+"/";
    ifstream archivo_entrada(url+"info.txt");;
    string infoval;
    getline(archivo_entrada, infoval);




    //guardar en un array nombres de las columnas
    string cola[50];
    for (int l = 0; l < 50; ++l) {
        cola[l] = "";
    }
    int inic=0;
    int ind=0;
    for (int j = 0; j <infoval.length(); ++j) {
        if(infoval[j]==','){
            string temp = infoval.substr(inic,j-inic);
            cola[ind]= temp;
            cont++;
            ind++;
            inic = j+1;
        }
    }




    int colum=0;
    for (int n = 0; n < 50; ++n) {
        if (cola[n]!="")
            colum++;
    }
    int filas=contfil(tabla,cola[1]);
    //llenar matriz de la tabla
    filas++;
    string matriz[filas+1][colum+1];


    ifstream archivo_entrad(url+"info.txt");
    string lol;
    cout << lol<<endl;
    getline(archivo_entrad, lol);
    camb_tovec2(lol);
    for (int j = 0; j < colum; ++j) {
        if(vect[j]==""){
            break;
        }
        matriz[0][j]=vect[j];
    }



    for (int i = 0; i < colum; ++i) {
        ifstream archivo_entrada(url+cola[i]+".txt");
        string linealect;
        getline(archivo_entrada, linealect);
        camb_tovec(linealect);
        for (int j = 0; j < filas; ++j) {
            if(vect[j]==""){
                break;
            }
            matriz[j+1][i]=vect[j];
        }
    }

    string result="";
    for (int k = 0; k <colum ; ++k) {
        for (int i = 0; i <filas ; ++i) {
            result = result+matriz[k][i]+",";
            result = result + ":";
        }
    }
    printf("%s\n",result);




    return result;

}

