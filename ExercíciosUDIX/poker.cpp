#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define NJOGADORES 4

using namespace std;

enum figura{dois = 2, tres, quatro, cinco, seis, sete, oito, nove, dez, valete, dama, rei, as};
enum simbolo{ouros, espadas, copas, paus};

string figuras[] = {" 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "VA", "DA", "RE", "AS"};
string simbolos[] = {"o", "e", "c", "p"};

class carta{
        figura valor;
        simbolo naipe;
    public:
        carta(figura valor = dois, simbolo naipe = ouros):valor(valor), naipe(naipe){};
        friend ostream& operator<<(ostream& out, const carta &c);
        carta operator++(int){
            carta aux(*this);
            if(valor == as){
                valor = dois;
                if(naipe == paus) naipe = ouros;
                else naipe = (simbolo) (naipe + 1);
            }
            else valor = (figura) (valor + 1);
            return aux;
        }
        bool operator<(const carta &c){
            return (valor < c.valor);
        }
        bool operator==(const figura f){
            return valor == f;
        }
};

ostream& operator<<(ostream& out, const carta &c){
    out << figuras[c.valor - dois] << simbolos[c.naipe];
    return out;
}

carta geraCarta(){
    static carta c(dois, ouros);
    return c++;
}

void imprimir(const vector<carta> baralho){
    for(int i=0; i<baralho.size(); i++){
        cout << baralho[i] << " ";
        if((i+1)%13 == 0) cout << endl;
    }
    cout << endl;
}

void imprimir_maos(const vector< vector<carta> > maos){
    vector< vector<carta> >::const_iterator it;
    for(it = maos.begin(); it != maos.end(); ++it){
        vector<carta>::const_iterator jt;
        cout << "Mão " << (int) (it - maos.begin()) + 1 << ": ";
        for(jt = it->begin(); jt != it->end(); jt++){
            cout << *jt << " ";
        }
        cout << endl;
    }
}

void imprimir_mesa(const vector<carta> mesa){
    vector<carta>::const_iterator it;
    cout << "Mesa: ";
    for(it = mesa.begin(); it != mesa.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    vector<carta> baralho(52);
    generate_n(baralho.begin(), 52, geraCarta);

    random_shuffle(baralho.begin(), baralho.end());
    cout << endl;
    imprimir(baralho);

    vector< vector<carta> > maos (NJOGADORES);
    vector<carta> mesa;

    // Saque inicial dos jogadores, cada um saca duas cartas
    vector< vector<carta> >::iterator it;
    for(int i = 0; i < 2; i++){
        for(it = maos.begin(); it != maos.end(); it++){
            carta aux = *(baralho.rbegin());
            baralho.pop_back();
            it->push_back(aux);
        }
    }
    imprimir_maos(maos);

    // Preenchendo a mesa
    baralho.pop_back();
    for(int i=0; i<3; i++){
        carta aux = *(baralho.rbegin());
        baralho.pop_back();
        mesa.push_back(aux);
    }
    for(int i=0; i<2; i++){
        baralho.pop_back();
        carta aux = *(baralho.rbegin());
        baralho.pop_back();
        mesa.push_back(aux);
    }
    imprimir_mesa(mesa);

    // Estendendo as mãos com as cartas da mesa
    vector<carta>::iterator itm;
    for(it = maos.begin(); it != maos.end(); ++it){
        for(itm = mesa.begin(); itm != mesa.end(); ++itm){
            it->push_back(*itm);
        }
    }
    imprimir_maos(maos);

    //imprimir(baralho);

    // Mostrando a maior carta de cada mão
    for(it = maos.begin(); it != maos.end(); ++it){
        cout << "Maior carta da mão " << (int)  (it - maos.begin() ) + 1 << ": " << *max_element(it->begin(), it->end()) << endl;
    }
    // Contando quantas vezes cada figura aparece em cada mão
    for(it = maos.begin(); it != maos.end(); ++it){
        bool dupla = false, trinca = false;
        for(figura f = dois; f <= as; f = (figura)(f+1)){
            int c = count(it->begin(), it->end(), f);
            if(c == 2){
                cout << "A mão " << (int)  (it - maos.begin() ) + 1 << " possui dupla de " 
                << figuras[f - dois] << endl;
                dupla = true;
            }
            else if(c == 3){
                cout << "A mão " << (int)  (it - maos.begin() ) + 1 << " possui trinca de " 
                << figuras[f - dois] << endl;
                trinca = true;
            }
            else if(c == 4){
                cout << "A mão " << (int)  (it - maos.begin() ) + 1 << " possui quadra de " 
                << figuras[f - dois] << endl;
            }
        }
        if(dupla && trinca){
            cout << "A mão " << (int)  (it - maos.begin() ) + 1 << " possui fullhouse" << endl;
        }
    }

    return 0;
}