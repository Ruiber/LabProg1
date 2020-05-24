#ifndef Ponto_h
#define Ponto_h

class Ponto{
private:
    double x, y, z;
public:
    Ponto(){ x = y = z = 0; } //Construtor default
    Ponto(double px, double py, double pz); //Construtor alternativo
    Ponto oposto(); //Retorna o oposto do ponto
    double distancia(Ponto p); //Retorna a distância entre os dois pontos
    double distancia(); //Retorna a distância do ponto à origem
    void visualizar(); //Imprime o ponto como tripla ordenada
};

#endif