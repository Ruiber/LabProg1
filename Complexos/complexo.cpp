#include <iostream>
#include <cmath>
#include "complexo.h"

using namespace std;

Complexo Complexo::soma(Complexo c){
    Complexo result;
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}

Complexo Complexo::mult(Complexo c){
    Complexo result;
    result.real = real * c.real - imag * c.imag;
    result.imag = real * c.imag + imag * c.real;
    return result;
}

Complexo Complexo::sub(Complexo c){
    Complexo result;
    result.real = real - c.real;
    result.imag = imag - c.imag;
    return result;
}

Complexo Complexo::div(Complexo c){
    Complexo result;
    double divisor = c.modulo()*c.modulo();
    result.real = (real*c.real + imag*c.imag)/divisor;
    result.imag = (-real*c.imag + imag*c.real)/divisor;
    return result;
}

Complexo Complexo::conjugado(){
    return Complexo(real, -imag);
}

double Complexo::modulo(){
    return sqrt(real*real + imag*imag);
}

void Complexo::imprimir(){
    cout << real;
    if(imag > 0){
        cout << " + " << imag << "i";
    }
    else if(imag < 0){
        cout << " - " << -imag << "i";
    }
    cout << endl;
}

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

    return 0;
}