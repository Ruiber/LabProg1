class Complexo{
    public:
        Complexo(double preal=0, double pimag=0){
            real = preal;
            imag = pimag;
        }
        double real, imag;
        Complexo soma(Complexo c);
        Complexo mult(Complexo c);
        Complexo sub(Complexo c);
        Complexo div(Complexo c);
        Complexo conjugado();
        double modulo();
        void imprimir();
};