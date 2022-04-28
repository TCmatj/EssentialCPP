#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

template <typename InputIterator, typename OutputIterator,
            typename ElemType,      typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
        OutputIterator at, const ElemType &val, Comp pred)
{
    while((first = find_if(first, last, bind2nd(pred, val))) != last){
        cout << "found value: " << *first << endl;
        *at++ = *first++;   //赋值后两个迭代器前进
    }
    return at;
}

int main(){
    vector<int> vec;
    int count;
    cout << "输入需要的斐波那契数列元素个数：";
    cin >> count;
    if(count <= 0){
            cerr << "范围有误\n";
            return 0;
    }
    for(int i = 0; i < count; i++){
        if(i == 0 || i == 1)
            vec.push_back(1);
        else
            vec.push_back(vec.back() + vec[vec.size() - 2]);
    }
    cout << "生成的元素：\n";
    for(vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
        cout << (*i) << ' ';
    cout << endl;

    int op,value;
    bool *op_fun;
    vector<int> nvec;

    cout << "输入需要查询的操作与值x：\n1:小于x\n2:大于x\n";
    cin >> op >> value;
    switch(op){
        case 1: 
            filter(vec.begin(), vec.end(),back_inserter(nvec), value, less<int>());
            break;
        case 2:
            filter(vec.begin(), vec.end(),back_inserter(nvec), value, greater<int>());
            break;
        default:
            cerr << "错误\n";
            break;
    }

    cout << "满足的元素：\n";
    for(vector<int>::iterator i = nvec.begin(); i < nvec.end(); i++)
        cout << (*i) << ' ';
    cout << endl;
        
    return 0;
}