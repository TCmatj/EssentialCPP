#include <iostream>
#include <vector>
#include "Triangular.h"
using namespace std;

int main(){
    Triangular tri(20);
    Triangular_iterator it = tri.begin();
    Triangular_iterator end_it = tri.end();

    cout << "Triangular Series of " << tri.length() << " elements\n";
    //cout << tri << endl;
    while(it != end_it){
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
    
    system("pause");
    return 0;
}
