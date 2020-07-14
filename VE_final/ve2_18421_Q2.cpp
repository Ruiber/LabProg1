#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class T{
        int entrada;
        vector<int> a;
    public:
        ostream *pos;
        T(int entrada):entrada(entrada), pos(NULL){}
        T& operator<<(const T& dir){
            if(pos == NULL){
                a.push_back(entrada);
                a.push_back(dir.entrada);
            }
            else{
                a.push_back(dir.entrada);
            }
            return *this;
        }
        T& operator>>(ostream& out){
            pos = &out;
            return *this;
        }
        T& operator>>(const T& dir){
            a.push_back(dir.entrada);
            return *this;
        }
        ostream& operator<<(const char& ch){
            sort(a.begin(), a.end());
            vector<int>::iterator it;
            for(it = a.begin(); it != a.end(); it++){
                *pos << *it << " ";
            }
            *pos << ch;

            return *pos;
        }
};

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    T(a) << T(b) >> cout >> T(c) << T(d) << '\n';
    
    return 0;
}