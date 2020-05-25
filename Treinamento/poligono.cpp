#include <iostream>
#include <cmath>

using namespace std;

class poligonoRegular{
private:
    int nLados;
    double compLado;
public:
    poligonoRegular(int pnLados, double pcompLado){
        if(!setnLados(pnLados)){
            nLados = 3;
        }
        if(!setcompLado(pcompLado)){
            compLado = 1;
        }
    }
    bool setnLados(int pnLados){
        if(pnLados >= 3){
            nLados = pnLados;
            return true;
        }
        return false;
    }
    int getnLados(){
        return nLados;
    }
    bool setcompLado(double pcompLado){
        if(pcompLado > 0){
            compLado = pcompLado;
            return true;
        }
        return false;
    }
    double getcompLado(){
        return compLado;
    }
    double somaAngulos(){
        return 4*atan(1)*(nLados - 2);
    }
    double perimetro(){
        return nLados*compLado;
    }
};

class trianguloEquilatero : public poligonoRegular{
public:
    trianguloEquilatero(double pcompLado):poligonoRegular(3, pcompLado){}
    double area(){
        return getcompLado()*getcompLado()*sqrt(3)/4;
    }
};

class Quadrado : public poligonoRegular{
public: 
    Quadrado(double pcompLado):poligonoRegular(4, pcompLado){}
    double area(){
        return getcompLado()*getcompLado();
    }
};

int main(){
    trianguloEquilatero T(5);
    Quadrado Q(4);

    cout << "Triângulo Equilátero de lado " << T.getcompLado() << "cm:\n";
    cout << "Perímetro: " << T.perimetro() << "cm" << endl;
    cout << "Soma dos ângulos internos: " << T.somaAngulos() << endl;
    cout << "Área: " << T.area() << "cm²" << endl;

    cout << endl;

    cout << "Quadrado de lado " << Q.getcompLado() << "cm:\n";
    cout << "Perímetro: " << Q.perimetro() << "cm" << endl;
    cout << "Soma dos ângulos internos: " << Q.somaAngulos() << endl;
    cout << "Área: " << Q.area() << "cm²" << endl;

    return 0;
}