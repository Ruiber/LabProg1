#include <iostream>
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

void Complexo::imprimir(){
    if(imag == 0){
        cout << real << endl;
    }
    else if(real == 0){
        cout << imag << "i" << endl;
    }
    else if(imag < 0){
        cout << real << " - " << -imag << "i" << endl;
    }
    else{
        cout << real << " + " << imag << "i" << endl;
    }
}

int main(){
    Complexo c1(3, 4), c2(5, -2), c3, c4;

    c3 = c1.soma(c2);
    c4 = c1.mult(c2);

    c1.imprimir();
    c2.imprimir();
    c3.imprimir();
    c4.imprimir();

    return 0;
}