#include <iostream>

using namespace std;

class Superpoder{
private:
    string nome;
    int categoria;
public:
    string getNome(){ return nome; }
    int getCategoria(){ return categoria; }
    Superpoder(string nome, int categoria):nome(nome), categoria(categoria){}
};

class Personagem{
private:
    string nome, nomeVidaReal;
    Superpoder **poderes;
    int nPoderes;
protected:
    Personagem(string nome, string nomeVidaReal):nome(nome), nomeVidaReal(nomeVidaReal){
        poderes = new Superpoder*[4];
        nPoderes = 0;
    }
public:
    ~Personagem(){
        delete []poderes;
    }
    Personagem(const Personagem &p){
        nome = p.nome;
        nomeVidaReal = p.nomeVidaReal;
        nPoderes = p.nPoderes;
        poderes = new Superpoder*[4];
        for(int i=0; i<nPoderes; i++)
            poderes[i] = p.poderes[i];
    }  
    string getNome(){ return nome; }
    string getNomeVidaReal(){ return nomeVidaReal; }
    bool adicionaSuperPoder(Superpoder &sp){
        if(nPoderes < 4){
            poderes[nPoderes++] = &sp;
            return true;
        }
        return false;
    }
    virtual double getPoderTotal(){
        double soma = 0;
        for(int i=0; i<nPoderes; i++){
            soma += poderes[i]->getCategoria();
        }
        return soma;
    }
};

class SuperHeroi:public Personagem{
public:
    SuperHeroi(string nome, string nomeVidaReal):Personagem(nome, nomeVidaReal){}
    double getPoderTotal(){
        return 1.1*Personagem::getPoderTotal();
    }
};

class Vilao:public Personagem{
    int tempoDePrisao;
public:
    Vilao(string nome, string nomeVidaReal, int tempoDePrisao):Personagem(nome, nomeVidaReal), tempoDePrisao(tempoDePrisao){}
    double getPoderTotal(){
        return (1 + 0.01*tempoDePrisao)*Personagem::getPoderTotal();
    }
};

class Confronto{
public:
    string enfrentar(SuperHeroi &p1, Vilao &p2){
        double poderHeroi = p1.getPoderTotal();
        double poderVilao = p2.getPoderTotal();
        if(poderHeroi > poderVilao){
            return p1.getNome();
        }
        else if(poderHeroi == poderVilao){
            return "empate";
        }
        return p2.getNome();
    }
};

int main(){
    Superpoder sp1("soltar teia", 3);
    Superpoder sp2("andar em paredes", 2);
    Superpoder sp3("sentido apurado", 1);
    Superpoder sp4("voar", 3);
    Superpoder sp5("força", 5);
    Superpoder sp6("visão de raio X", 4);
    Superpoder sp7("sopro congelante", 4);
    Superpoder sp8("supersoldado", 3);
    Superpoder sp9("escudo", 3);
    Superpoder sp10("velocidade", 5);
    Superpoder sp11("anel mágico", 5);
    Superpoder sp12("armadura", 4);
    Superpoder sp13("dispositivos eletrônicos", 2);
    Superpoder sp14("mente aguçada", 5);
    Superpoder sp15("tentáculos indestrutíveis", 5);
    Superpoder sp16("velocidade", 1);

    SuperHeroi sh1("Homem-Aranha", "Peter Parker");
    SuperHeroi sh2("Super-Homem", "Clark Kent");
    SuperHeroi sh3("Capitão América", "Steve Rogers");
    SuperHeroi sh4("Flash", "Barry Allen");
    SuperHeroi sh5("Lanterna Verde", "Hal Jordan");
    SuperHeroi sh6("Homem de Ferro", "Tony Stark");

    Vilao v1("Duende Verde", "Norman Osbourne", 3);
    Vilao v2("Lex Luthor", "Lex Luthor", 5);
    Vilao v3("Bizarro", "Bizarro", 11);
    Vilao v4("Octopus", "Otto Octavius", 4);

    sh1.adicionaSuperPoder(sp1);
    sh1.adicionaSuperPoder(sp2);
    sh1.adicionaSuperPoder(sp3);
    sh2.adicionaSuperPoder(sp4);
    sh2.adicionaSuperPoder(sp5);
    sh2.adicionaSuperPoder(sp6);
    sh2.adicionaSuperPoder(sp7);
    sh3.adicionaSuperPoder(sp8);
    sh3.adicionaSuperPoder(sp9);
    sh4.adicionaSuperPoder(sp10);
    sh5.adicionaSuperPoder(sp11);
    sh6.adicionaSuperPoder(sp12);
    sh6.adicionaSuperPoder(sp13);

    v1.adicionaSuperPoder(sp5);
    v2.adicionaSuperPoder(sp14);
    v3.adicionaSuperPoder(sp4);
    v3.adicionaSuperPoder(sp5);
    v3.adicionaSuperPoder(sp6);
    v3.adicionaSuperPoder(sp7);
    v4.adicionaSuperPoder(sp15);
    v4.adicionaSuperPoder(sp16);

    SuperHeroi herois[6] = {sh1, sh2, sh3, sh4, sh5, sh6};
    Vilao viloes[4] = {v1, v2, v3, v4};
    Confronto c;

    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            cout << "Confronto #" << 4*i + j + 1 << ":" << endl;
            cout << herois[i].getNome() << " versus " << viloes[j].getNome() << endl;
            cout << "E o vencedor é: " << c.enfrentar(herois[i], viloes[j]) << endl << endl;
        }
    }

    return 0;
}