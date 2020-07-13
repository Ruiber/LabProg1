#include <iostream>
#include <sstream>

using namespace std;

class AcessoInvalido{
    public:
        string linha;
        int pos, qnt;
        AcessoInvalido(string linha, int pos, int qnt):
        linha(linha), pos(pos), qnt(qnt){}
        string mensagem(){
            ostringstream erro;
            erro <<  "Erro na linha " << linha << " você tentou acessar a posição "
            << pos << " que é uma posição inválida. O seu conjunto tem " << qnt
            << " elementos" << endl;
            
            return erro.str();
        }
};

template<typename T>
class conjunto{
        T *elementos;
        int tamanho, qnt;
    public:
        // Construtor
        conjunto(int tamanho = 10):tamanho(tamanho){
            qnt = 0;
            elementos = new T[tamanho];
        }
        // Destrutor
        ~conjunto(){
            delete[] elementos;
        }
        // Operadores:
        // Inserção
        conjunto& operator+=(T elemento){
            if(qnt == tamanho) return *this;
            for(int i=0; i<qnt; i++){
                if(elementos[i] == elemento) return *this;
            }
            elementos[qnt++] = elemento;
            return *this;
        }
        // União
        conjunto& operator+=(const conjunto& c){
            for(int i=0; i<c.qnt; i++){
                *this += c.elementos[i];
            }
            return *this;
        }
        // Remoção
        conjunto& operator-=(T elemento){
            for(int i=0; i<qnt; i++){
                if(elementos[i] == elemento){
                    elementos[i] = elementos[--qnt];
                    break;
                }
            }
            return *this;
        }
        // Diferença
        conjunto& operator-=(const conjunto& c){
            for(int i=0; i<c.qnt; i++){
                *this -= c.elementos[i];
            }
            return *this;
        }
        // Interseção
        conjunto& operator*=(const conjunto& c){
            for(int i=qnt-1; i>=0; i--){
                int j;
                for(j=0; j<c.qnt; j++){
                    if(c.elementos[j] == elementos[i]) break;
                }
                if(j == c.qnt) *this -= elementos[i];
            }
            return *this;
        }
        // Acesso indexado
        T operator[](int i){
            if(i >= 0 && i < qnt) return elementos[i];
            throw AcessoInvalido("return elemento[i]", i, qnt);
        }
        // Impressão
        void operator!(){
            cout << "{";
            for(int i=0; i<qnt-1; i++){
                cout << elementos[i] << ", ";
            }
            if(qnt > 0) cout << elementos[qnt-1];
            cout << "}" << endl;
        }
        // Tamanho
        operator int(){
            return tamanho;
        }
};

int main(){
    conjunto<int> C1, C2(7);
    
    cout << (int) C1 << endl;
    cout << (int) C2 << endl;

    (((((C1 += 1) += 2) += 3) += 4) += 5) += 1;
    (((((C2 += 2) += 3) += 6) += 7) += 8) += 9;
    !C1;
    !C2;
    !(C1 += C2);
    !(C1 -= C2);
    !(C1 -= 5);
    !(C1 *= C2);
    try{
        for(int i=0; i<7; i++)
            cout << C2[i] << endl;
    }
    catch(AcessoInvalido erro){
        cout << "Mensagem de erro: " << erro.mensagem();
        return 1;
    }
    catch(...){
        cout << "Erro fatal\n";
        return 2;
    }

    return 0;
}