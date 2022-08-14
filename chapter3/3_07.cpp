#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> filter_ver(const vector<int> &vec,
                        int val,
                        less<int> lt){  //原为less<int> &lt 有错误
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    while((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end()){    
        //bind2nd将less<int>,即“小于”的两个参数的第二个参数绑定为val
        nvec.push_back(*iter);
        iter++;
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

    int value;
    vector<int> nvec;

    cout << "输入小于的值x：\n";
    cin >> value;
    
    nvec = filter_ver(vec, value, less<int>());

    cout << "满足的元素：\n";
    for(vector<int>::iterator i = nvec.begin(); i < nvec.end(); i++)
        cout << (*i) << ' ';
    cout << endl;

    return 0;
}