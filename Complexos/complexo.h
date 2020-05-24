class Complexo{
    public:
        Complexo(double preal=0, double pimag=0){
            real = preal;
            imag = pimag;
        }
        double real, imag;
        Complexo soma(Complexo c);
        Complexo mult(Complexo c);
        void imprimir();
};