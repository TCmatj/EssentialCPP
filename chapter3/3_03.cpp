#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> aline;
    int ival;
    while(cout << "输入一个数值：",cin >> ival){
        aline.push_back(ival);
        int currvalue = aline.front();
        cout << currvalue << endl;

        aline.pop_front();
    }
    return 0;
}