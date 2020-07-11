#include <iostream>

using namespace std;

class complex{
    double real, imag;
    public:
        complex(double real = 0, double imag = 0):
        real(real), imag(imag){}
        complex(const complex &c):
        real(c.real), imag(c.imag){}
        double getReal() const{ return real; }
        double getImag() const{ return imag; }
        void print() const{
            cout << real;
            if(imag > 0) cout << " + " << imag << "i";
            else if(imag < 0) cout << " - " << -imag << "i";
            cout << endl;
        }
        friend bool operator!(const complex &c);
        complex operator+(const complex &c){ return complex(real + c.real, imag + c.imag); }
        complex &operator+=(const complex &c){
            *this = *this + c;
            return *this;
        }
        complex operator-(){ return complex(-real, -imag); }
        complex &operator++(){ 
            ++real;
            return *this;
        }
        complex operator++(int){
            return complex(real++, imag);
        }
        complex operator-(const complex &c){ return complex(real - c.real, imag - c.imag); }
        complex &operator-=(const complex &c){
            *this = *this - c;
            return *this;
        }
        complex operator+(const double &n){ return complex(real + n, imag); }
        bool operator==(const complex &c){ return (real == c.real && imag == c.imag); }
        operator double(){ return real; }
        friend complex operator+(const int &n, complex &c);
};
bool operator!(const complex &c){ return (c.real == 0 && c.imag == 0); }
complex operator+(const int &n, complex &c){ return complex(n + c.real, c.imag); }

int main(){
    complex c1(3, 4), c2(0, 0), c3(2, -5), c4(c1 + c3), c5(7, -1);
    cout << !c1 << " " << !c2 << endl;
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c4 += c3;
    c4.print();
    (-c4).print();
    (++c4).print();
    c4++.print();
    c4.print();
    (c1 - c3).print();
    (c4 -= c3).print();
    cout << (c4 == c5) << " " << (c4 == c3) << endl;
    cout << (double) c4 << endl;
    (3 + c4).print();

    return 0;
}