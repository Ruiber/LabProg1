#ifndef matriz_h
#define matriz_h

class Matriz{
    double a, b, c, d;
public:
    Matriz(double pa=0, double pb=0, double pc=0, double pd=0){
        a = pa;
        b = pb;
        c = pc;
        d = pd;
    }
    double geta(){ return a; }
    double getb(){ return b; }
    double getc(){ return c; }
    double getd(){ return d; }
    Matriz inversa();
    double det();
    void visualizar();
};

#endif