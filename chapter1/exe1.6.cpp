#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> ivec;
    int ival;
    int sum = 0;
    int i;
    while(cin >> ival){
        ivec.push_back(ival);
    }
    for(i = 0;i < ivec.size();i++){
        sum += ivec[i];
    }
    cout << "sum = " << sum << " average = " << sum/(i+1) <<endl;
    return 0;
}