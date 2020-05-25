#ifndef data_h
#define data_h

class Data{
    int dia, mes, ano;
public:
    Data(){
        reiniciar(1, 1, 1);
    }
    Data(int pdia, int pmes, int pano){
        reiniciar(pdia, pmes, pano);
        normalizar();
    }
    void reiniciar(int pdia, int pmes, int pano);
    int getdia(){ return dia; }
    int getmes(){ return mes; }
    int getano(){ return ano; }
    void imprimir();
    void normalizar();
    bool bissexto(int pano);
    int dias(int pmes, int pano);
    void adiantar(int pdia, int pmes, int pano);
};

#endif