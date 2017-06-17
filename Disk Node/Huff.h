//
// Created by nano on 16/06/17.
//
#include <iostream>


using namespace std;

string Huff(string tabla){
    string valor;
    for (int i = 0; i <tabla.length(); ++i) {
        if(tabla[i]=='A' || tabla[i]=='a'){
            valor+="1";
        }else if(tabla[i]=='B' || tabla[i]=='b'){
            valor+="2";
        }else if(tabla[i]=='C' || tabla[i]=='c'){
            valor+="3";
        }else if(tabla[i]=='D' || tabla[i]=='d'){
            valor+="4";
        }else if(tabla[i]=='E' || tabla[i]=='e'){
            valor+="5";
        }else if(tabla[i]=='F' || tabla[i]=='f'){
            valor+="6";
        }else if(tabla[i]=='G' || tabla[i]=='g'){
            valor+="7";
        }else if(tabla[i]=='H' || tabla[i]=='h'){
            valor+="8";
        }else if(tabla[i]=='I' || tabla[i]=='i'){
            valor+="9";
        }else if(tabla[i]=='J' || tabla[i]=='j'){
            valor+="10";
        }else if(tabla[i]=='K' || tabla[i]=='k'){
            valor+="1";
        }else if(tabla[i]=='L' || tabla[i]=='l'){
            valor+="12";
        }else if(tabla[i]=='M' || tabla[i]=='m'){
            valor+="13";
        }else if(tabla[i]=='N' || tabla[i]=='n'){
            valor+="14";
        }else if(tabla[i]=='O' || tabla[i]=='o'){
            valor+="15";
        }else if(tabla[i]=='P' || tabla[i]=='p'){
            valor+="16";
        }else if(tabla[i]=='Q' || tabla[i]=='q'){
            valor+="17";
        }else if(tabla[i]=='R' || tabla[i]=='r'){
            valor+='18';
        }else if(tabla[i]=='S' || tabla[i]=='s'){
            valor+="19";
        }else if(tabla[i]=='T' || tabla[i]=='t'){
            valor+="20";
        }else if(tabla[i]=='U' || tabla[i]=='u'){
            valor+="21";
        }else if(tabla[i]=='V' || tabla[i]=='v'){
            valor+="22";
        }else if(tabla[i]=='W' || tabla[i]=='w'){
            valor+="23";
        }else if(tabla[i]=='X' || tabla[i]=='x'){
            valor+="24";
        }else if(tabla[i]=='Y' || tabla[i]=='y'){
            valor+="25";
        }else if(tabla[i]=='Z' || tabla[i]=='z'){
            valor+="26";
        }
    }

    return valor;

}