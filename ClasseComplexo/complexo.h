#ifndef Complexo_h
#define Complexo_h

class Complexo{
    double real, imag;
    public:
        Complexo(double preal=0, double pimag=0);
        Complexo soma(Complexo c);
        Complexo mult(Complexo c);
        Complexo sub(Complexo c);
        Complexo div(Complexo c);
        Complexo conjugado();
        double modulo();
        void imprimir();
        double getReal(){ return real; }
        double getImag(){ return imag; }
};

#endif