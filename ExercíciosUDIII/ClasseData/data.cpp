#include <iostream>
#include "data.h"

using namespace std;

void Data::reiniciar(int pdia, int pmes, int pano){
    dia = pdia;
    mes = pmes;
    ano = pano;
    normalizar();
}

void Data::imprimir(){
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

void Data::normalizar(){
    if(ano<1 || mes<1 || dia<1){
        cout << "Erro\n";
        return;
    }
    while(dia > dias((mes-1)%12 + 1, ano)){
        dia -= dias((mes-1)%12 + 1, ano);
        mes += 1;
    }
    if(mes > 12){
        ano += (mes-1)/12;
        mes = (mes-1)%12 + 1;
    }
}

bool Data::bissexto(int pano){
    if(pano%400==0 || (pano%4==0 && pano%100!=0))
        return true;
    else
        return false;
}

int Data::dias(int pmes, int pano){
    switch(pmes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28 + bissexto(pano);
    }
}

void Data::adiantar(int pdia, int pmes, int pano){
    dia += pdia;
    mes += pmes;
    ano += pano;
    normalizar();
}