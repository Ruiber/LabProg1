#include <iostream>

using namespace std;

class empregado{
    static int nEmpregados;
    const string nome;
    int salario, ramal;
    public:
        static bool permite;
        void confereNumero(){
            if(!permite) return;
            cout << "A empresa tem " << nEmpregados << " empregados atualmente." << endl;
            if(nEmpregados < 10){
                cout << "O numero minimo de empregados eh 10, faltam pelo menos " << 10 - nEmpregados << " empregados." << endl;
            }
            else if(nEmpregados <= 50){
                cout << "O numero de empregados encontra-se dentro do intervalo permitido." << endl;
            }
            else{
                cout << "A empresa excedeu em " << nEmpregados - 50 << " o numero de empregados permitido." << endl;
            }
        }
        empregado(string nome, int salario, int ramal):
        nome(nome), salario(salario), ramal(ramal){
            nEmpregados++;
            confereNumero();
        }
        empregado(const empregado &e):
        nome(e.nome), salario(e.salario), ramal(e.ramal){
            nEmpregados++;
            confereNumero();
        }
        ~empregado(){
            nEmpregados--;
            confereNumero();
        }
        string getNome() const{ return nome; }
        int getSalario() const{ return salario; }
        int getRamal() const{ return ramal; }
        void setSalario(int salario){ this->salario = salario; }
        void setRamal(int ramal){ this->ramal = ramal; }
};
int empregado::nEmpregados = 0;
bool empregado::permite = true;

int main(){
    empregado *e[52], e1("Carlos", 3000, 53);
    for(int i=1; i<=52; i++)
        e[i] = new empregado(e1);
    
    for(int i=1; i<=52; i++)
        delete e[i];

    empregado::permite = false;

    return 0;
}