#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(){
    ostringstream test;
    test << "Teste maneiro: " << 3 << endl;
    test << "Segundo teste maneiro: " << .75 << endl;
    cout << test.str();

    string s = test.str();
    printf("%s", s.c_str());

    return 0;
}