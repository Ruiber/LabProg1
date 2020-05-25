#include <iostream>
#include "matriz.h"

using namespace std;

Matriz Matriz::inversa(){
    if(det()==0){
        cout << "Matriz não-inversível.\n";
    }
    else{
        double det = this->det();
        return Matriz(d/det, -b/det, -c/det, a/det);
    }
}

double Matriz::det(){
    return a*d - b*c;
}

void Matriz::visualizar(){
    cout << "|" << a << " " << b << "|" << endl;
    cout << "|" << c << " " << d << "|" << endl;
}