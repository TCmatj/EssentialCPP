#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> svec(10);
    vector<int>::iterator iter = svec.begin();
    for(int i=0;i<5;i++,iter++)
        *iter = i+1;
    for(iter=svec.begin();iter!=svec.end();iter++)
        cout << *iter << ' ';
    return 0;
}