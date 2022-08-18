#include <iostream>
#include "Triangular.h"
using namespace std;

istream& operator>>(istream &is,Triangular &rhs);
int main(){
    Triangular tri(6,3);
    cout << tri << '\n';

    Triangular tri2;
    cin >> tri2;
    //看看输入了什么
    cout << tri2;
    
    system("pause");
    return 0;
}