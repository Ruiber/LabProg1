#include <iostream>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

class NumeroRacional{
    int num, den;
    public:
        NumeroRacional(int num = 1, int den = 1){
            if(den != 0){
                this->num = num;
                this->den = den;
                ajustar();
            }
            else throw "Erro";
        }
        NumeroRacional(const NumeroRacional &q):
        num(q.num), den(q.den){}
        void ajustar(){
            int d;
            if(den < 0){
                num = -num;
                den = -den;
            }
            if(num > 0) d = mdc(num, den);
            else d = mdc(-num, den);
            num /= d;
            den /= d;
        }
        void print() const{
            cout << num << "/" << den << endl;
        }
        NumeroRacional operator+(const NumeroRacional &q){
            return NumeroRacional(num*q.den + den*q.num, den*q.den);
        }
        NumeroRacional &operator=(const NumeroRacional &q){
            num = q.num;
            den = q.den;
            return *this;
        }
        NumeroRacional operator/(const NumeroRacional &q){
            return NumeroRacional(num * q.den, den * q.num);
        }
        NumeroRacional &operator++(){
            num += den;
            return *this;
        }
        NumeroRacional operator++(int){
            NumeroRacional aux(*this);
            num += den;
            return aux;
        }
        operator float(){
            float aux = ((float) num)/den;
            return aux;
        }
};

int main(){
    NumeroRacional p(2, 4), q(30, -42), r(-700, -630), s;
    p.print();
    q.print();
    r.print();
    s = p + q;
    s.print();
    s = p/q;
    s.print();
    (++s).print();
    s++.print();
    s.print();
    cout << (float) s << endl;
    cout << (float) r << endl;
    cout << (float) q << endl;
    cout << (float) p << endl;

    return 0;
}