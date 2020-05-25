#ifndef Ponto_h
#define Ponto_h

class Ponto{
private:
    double x, y, z;
public:
    Ponto(){ x = y = z = 0; } //Construtor default
    Ponto(double px, double py, double pz); //Construtor alternativo
    Ponto oposto(); //Retorna o oposto do ponto
    double distancia(Ponto p = Ponto(0, 0, 0)); //Retorna a distância entre os dois pontos
    void visualizar(); //Imprime o ponto como tripla ordenada
};

#endif