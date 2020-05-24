//Testando a implementação de construtor por cópia e destrutor quando lidamos com alocação dinâmica.
#include <iostream>
#include <cstdlib>

using namespace std;

class Dinamica{
private:
    int *vet;
public:
    Dinamica(){  //Construtor default
        vet = (int *)malloc(sizeof(int)*10);
        cout << "Construtor Default: " << (long long) vet << endl;
    }
    Dinamica(const Dinamica &p){  //Construtor por cópia
        vet = (int *)malloc(sizeof(int)*10);
        for(int i=0; i<10; i++)
            vet[i] = p.vet[i];
        cout << "Construtor por cópia: " << (long long) vet << endl;
    }
    ~Dinamica(){  //Destrutor
        cout << "Destrutor: " << (long long) vet << endl;
        free(vet);
    }
};

int main(){
    Dinamica d1, d2;
    Dinamica d3 = d1;

    return 0;
}