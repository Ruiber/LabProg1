#include <iostream>

using namespace std;

class counter{
    static int count;
    public:
        static int getCount(){ return count; }
        counter(){ count++; }
        ~counter(){ count--; }
};

int counter::count = 0;

int main(){
    counter c1, c2;
    cout << counter::getCount() << endl;
    {
        counter c4;
        cout << counter::getCount() << endl;
    }
    cout << counter::getCount() << endl;

    return 0;
}