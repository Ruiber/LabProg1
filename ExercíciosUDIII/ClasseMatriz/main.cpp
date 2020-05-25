#include <iostream>
#include "matriz.h"

using namespace std;

int main(){
    Matriz M(2, 4, 3, 6), N(1, 3, 2, 5);
    
    cout << "Matriz M:" << endl;
    M.visualizar();
    cout << "Determinante de M: " << M.det() << endl;
    cout << "Inversa de M:" << endl;
    M.inversa();

    cout << endl;

    cout << "Matriz N:" << endl;
    N.visualizar();
    cout << "Determinante de N: " << N.det() << endl;
    cout << "Inversa de N:" << endl;
    N.inversa().visualizar();

    return 0;
}