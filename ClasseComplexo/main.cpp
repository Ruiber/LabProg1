#include <iostream>
#include <cmath>
#include "complexo.h"

using namespace std;

int main(){
    Complexo c1(3, 4), c2(2, 3), c3;
    
    cout << "Complexo 1: ";
    c1.imprimir();
    cout << "Complexo 2: ";
    c2.imprimir();
    
    cout << "Soma: ";
    c3 = c1.soma(c2);
    c3.imprimir();

    cout << "Produto: ";
    c3 = c1.mult(c2);
    c3.imprimir();

    cout << "Subtração: ";
    c3 = c1.sub(c2);
    c3.imprimir();

    cout << "Divisão: ";
    c3 = c1.div(c2);
    c3.imprimir();

    cout << "Conjugado do complexo 1: ";
    c3 = c1.conjugado();
    c3.imprimir();

    cout << "Conjugado do complexo 2: ";
    c3 = c2.conjugado();
    c3.imprimir();

    cout << "Módulo do complexo 1: ";
    c3 = c1.modulo();
    c3.imprimir();

    cout << "Módulo do complexo 2: ";
    c3 = c2.modulo();
    c3.imprimir();

    cout << "Testando os getters no complexo 1: ";
    cout << c1.getReal() << " + " << c1.getImag() << "i" << endl;

    return 0;
}