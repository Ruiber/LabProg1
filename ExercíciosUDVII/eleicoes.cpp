#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

class candidato{
    static int total_votos;
    int num, votos;
    double porcentagem;
    string nome;
    string partido;
    public:
        // Construtor
        candidato(int num, string nome, string partido):
        num(num), nome(nome), partido(partido), votos(0){}
        candidato(const candidato& c):
        num(c.num), nome(c.nome), partido(c.partido), votos(c.votos){}
        // Getters
        int getNum() const{ return num; }
        int getVotos() const{ return votos; }
        double getPorcentagem() const{ return porcentagem; }
        string getNome() const{ return nome; }
        string getPartido() const{ return partido; }
        static int getTotal() { return total_votos; }
        // Método para votar num candidato
        void votar(){
            votos++;
            total_votos++;
        }
        // Método para estabelecer a porcentagem
        void setPorcentagem(){
            porcentagem = (votos / (double) total_votos) * 100;
        }
        // Operadores de ordem
        bool operator > (const candidato& c) const{
            return (votos > c.votos);
        }
};
int candidato::total_votos = 0;

int main(){
    ifstream inputs;
    vector<candidato> candidatos;
    stringstream urna;

    // Recebendo os candidatos e armazenando na memória
    inputs.open("candidatos.txt", ios::in);
    if(!inputs.is_open()){
        cout << "Erro\n";
        return 1;
    }
    while(!inputs.eof()){
        int numero;
        string nome, partido;
        inputs >> numero >> nome >> partido;
        if(inputs.good()) candidatos.push_back(candidato(numero, nome, partido));
    }
    inputs.close();
    
    // Recebendo nomes das urnas
    for(int i=1; i<5; i++)
        urna << "urna" << i << ".txt" << endl;
    // Lendo as votações das urnas
    for(int i=1; i<5; i++){
        string nomeArq;
        urna >> nomeArq;
        inputs.open(nomeArq.c_str(), ios::in);
        while(!inputs.eof()){
            int voto;
            inputs >> voto;
            if(inputs.good()) candidatos[voto-1].votar();
        }
        inputs.close();
    }
    cout << candidato::getTotal() << endl;
    
    // Ordenando os candidatos de acordo com o número de votos, do maior pro menor
    sort(candidatos.begin(), candidatos.end(), greater<candidato>());
    // Definindo as porcentagens
    for(int i=0; i<20; i++){
        candidatos[i].setPorcentagem();
    }
    // Imprimino resultado das eleições na tela
    cout << "Resultado das eleições" << endl;
    cout << "--------------------------------------------" <<  endl;
    cout << setiosflags(ios::left) << setw(9) << "Posição " << setw(9) << "Nome" << setw(8) << "Partido" << setw(7) << "Votos" << setw(10) << "Porcentagem\n";
    cout << "--------------------------------------------" << endl;
    for(int i=0; i<20; i++){
        cout << setw(9) << i+1 << setw(9) << candidatos[i].getNome() << setw(8) << candidatos[i].getPartido() << setw(7) << candidatos[i].getVotos() << setw(10) << candidatos[i].getPorcentagem() << endl;
    }

    return 0;
}