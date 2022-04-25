#include <iostream>
using namespace std;

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int main(){
    int x=5, y=3;
    int (*pf)(int ,int) = &add;
    cout << pf(x,y) << endl;
    return 0;
}