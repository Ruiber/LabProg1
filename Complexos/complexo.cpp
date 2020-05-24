#include "complexo.h"
#include <iostream>
#include <cmath>

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