#include <iostream>
#include <cmath>
#include "Ponto.h"

using namespace std;

Ponto::Ponto(double px, double py, double pz){
    x = px;
    y = py;
    z = pz;
}

Ponto Ponto::oposto(){
    return Ponto(-x, -y, -z);
}

double Ponto::distancia(Ponto p){
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z));
}

double Ponto::distancia(){
    return distancia(Ponto(0, 0, 0));
}

void Ponto::visualizar(){
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}