#include <iostream>

using namespace std;

class complexo{
    double a, b;
    friend istream &operator>>(istream &in, complexo &c);
    friend ostream &operator<<(ostream &out, const complexo &c);
};

istream &operator>>(istream &in, complexo &c){
    in >> c.a >> c.b;
    return in;
}

ostream &operator<<(ostream &out, const complexo &c){
    out << c.a;
    if(c.b > 0) out << " + " << c.b << "i";
    else if(c.b < 0) out << " - " << -c.b << "i";
    out << endl;
    return out;
}

int main(){
    complexo c;

    cin >> c;
    cout << c;

    return 0;
}