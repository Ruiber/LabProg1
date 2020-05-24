//Testando hierarquia de classe e modificadores de visibilidade
#include <iostream>

using namespace std;

class Base{
    void privado(){
        cout << "Base Privado\n";
    }
protected:
    void protegido(){
        cout << "Base Protegido\n";
    }
public:
    void publico(){
        cout << "Base Público\n";
    }
    void qualquer1(){
        privado();
        protegido();
        publico();
    }
};

class Herdada : protected Base{
public:
    void qualquer2(){
        protegido();
        publico();
    }
};

class Derivada : public Herdada{
public:
    void qualquer3(){
        protegido();
        publico();
    }
};

int main(){
    Base b;
    b.publico();
    b.qualquer1(); 
    
    Herdada h;
    h.qualquer2();
    
    Derivada d;
    d.qualquer3();

    return 0;
}