//Exemplo de uso da classe ponto criada.
#include <iostream>
#include "Ponto.h"

using namespace std;

int main(){
    Ponto p1, p2(3, -4, -5), p3(5, -3, 10);
    
    cout << "Ponto iniciado pelo construtor default (ponto 1): ";
    p1.visualizar();
    cout << "Ponto 2: ";
    p2.visualizar();
    cout << "Ponto 3: ";
    p3.visualizar();
    
    cout << "Oposto do ponto 2: ";
    p2.oposto().visualizar();
    cout << "Oposto do ponto 3: ";
    p3.oposto().visualizar();

    cout << "Distância do ponto 2 para a origem: " << p2.distancia() << endl;
    cout << "Distância do ponto 3 para a origem: " << p3.distancia() << endl;
    cout << "Distância entre os pontos 2 e 3: " << p2.distancia(p3) << endl;

    return 0;
}