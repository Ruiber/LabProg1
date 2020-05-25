#include <iostream>
#include "data.h"

using namespace std;

int main(){
    Data hoje(25, 5, 2020);
    hoje.imprimir();
    hoje.adiantar(74, 29, 1032);
    hoje.imprimir();
    hoje.reiniciar(3, 10, 1999);
    hoje.imprimir();

    return 0;
}