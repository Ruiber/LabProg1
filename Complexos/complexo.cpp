#include <iostream>

using namespace std;

class Complexo{
    public:
        int real, imag;
        Complexo soma(Complexo c){
            Complexo result;
            result.real = real + c.real;
            result.imag = imag + c.imag;
            return result;
        }
};

int main(){
    Complexo c1, c2, c3;
    c1.real = 3;
    c1.imag = 4;
    c2.real = 5;
    c2.imag = -2;

    c3 = c1.soma(c2);

    cout << c3.real << " + " << c3.imag << "i" << endl;

    return 0;
}