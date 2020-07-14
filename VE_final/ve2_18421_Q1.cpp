#include <iostream>
#include <vector>

using namespace std;

class Sudoku{
        vector< vector<int> > grid;
    public:
        // Construtor
        Sudoku(){
            grid.resize(9);
            vector< vector<int> >::iterator it;
            for(it = grid.begin(); it != grid.end(); ++it){
                it->resize(9, 0);
            }
        }
        // Método para configurar o grid inicial
        void setGrid(const vector< vector<int> > inicial){
            grid = inicial;
        }
        // Imprimir o grid
        friend ostream& operator<<(ostream &out, const Sudoku &tabela);
        // Verificar se um dado valor é possível
        bool verifica(int valor, int linha, int coluna){
            // Se o valor é inválido
            if(valor > 9 || valor < 1) return false;
            // Se já tem algum valor na posição
            if(grid[linha][coluna] != 0) return false;
            // Verificar na linha
            for(int j=0; j<9; j++){
                if(grid[linha][j] == valor) return false;
            }
            // Verificar na coluna
            for(int i=0; i<9; i++){
                if(grid[i][coluna] == valor) return false;
            }
            // Verifica na região
            int regiao_hor = coluna/3;
            int regiao_ver = linha/3;
            for(int i = 3*regiao_ver; i < 3*regiao_ver + 3; i++){
                for(int j = 3*regiao_hor; j< 3*regiao_hor + 3; j++){
                    if(grid[i][j] == valor) return false;
                }
            }
            // Se verificamos todos os e nenhum deu false, é pq é válido
            return true;
        }
        bool resolve(){
            int linha, coluna;
            bool zero = false;
            // Procuramos se ainda tem algum lugar sem valores atribuídos
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    // Se encontrarmos um 0, quer dizer que temos uma posição ainda sem valor atribuído
                    if(grid[i][j] == 0){
                        linha = i;
                        coluna = j;
                        zero = true;
                        break;
                    }
                }
            }
            // Se não encontramos posições sem valor atribuído, então o sudoku está resolvido
            if(!zero) return true;

            // Dado que encontramos possição sem valor atribuído,
            // estamos buscando qual valor pode entrar naquela posição
            for (int val = 1; val <= 9; val++){
                if (verifica(val, linha, coluna)){
                    grid[linha][coluna] = val;
                    // Aqui usamos a recursão para ver se esse caminho vai dar em solução,
                    // para o caso em que mais de um valor serve
                    if (resolve()) return true;
                    // Se o valor não der em um caminho bom, voltamos com 0 e continuamos a testar
                    grid[linha][coluna] = 0;
                }
            }
            return false;
        }
};

ostream& operator<<(ostream &out, const Sudoku &tabela){
    vector< vector<int> >::const_iterator i;
    vector<int>::const_iterator j;
    for(i = (tabela.grid).begin(); i != (tabela.grid).end(); ++i){
        for(j = i->begin(); j != i->end(); ++j){
            out << *j << " ";
        }
        out << endl;
    }
    return out;
}

int main(){
    Sudoku s;
    // Configuração inicial igual ao exemplo da prova
    vector< vector<int> > inicial = {
                                    {5, 3, 0, 0, 7, 0, 0, 0, 0},
                                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                    {0, 0, 0, 0, 8, 0, 0, 7, 9}
                                    };
    
    // Configurando nosso tabuleiro e exibindo ele
    s.setGrid(inicial);
    cout << "Sudoku inicial:" << endl;
    cout << s << endl;;
    
    // Resolvendo o Sudoku
    if(s.resolve()){
        cout << "Sudoku resolvido:" << endl;
        cout << s;
    }
    else{
        cout << "Não há solução para essa configuração inicial\n";
    }
    
    return 0;
}