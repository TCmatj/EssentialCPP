#include <iostream>
#include <vector>
using namespace std;

bool less_than(int v1, int v2){
    return v1 < v2 ? true : false;
}

bool greater_than(int v1, int v2){
    return v1 > v2 ? true : false;
}

vector<int> filter_ver(const vector<int> &vec,
                        int filter_value,
                        bool (*pred)(int, int)){    //pred为函数指针
    vector<int> nvec;

    for(int ix=0; ix < vec.size(); ix++){
        //调用pred函数
        //比较vec[ix]和filter_value
        if(pred(vec[ix], filter_value))
            nvec.push_back(vec[ix]);
    }
    return nvec;
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
            nvec = filter_ver(vec, value, less_than);
            break;
        case 2:
            nvec = filter_ver(vec, value, greater_than);
            break;
        default:
            cerr << "错误\n";
    }
    
    cout << "满足的元素：\n";
    for(vector<int>::iterator i = nvec.begin(); i < nvec.end(); i++)
        cout << (*i) << ' ';
    cout << endl;

    return 0;
}