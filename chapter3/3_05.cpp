#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

extern bool grow_vec(vector<int>&, int );

bool is_elem(vector<int> &vec, int elem){
    int max_value = *max_element(vec.begin(), vec.end() );
    if(max_value < elem)
        return grow_vec(vec, elem);
    if(max_value == elem)
        return true;
    return binary_search(vec.begin(), vec.end(), elem);
}

bool grow_vec(vector<int>& vec, int elem){
    while(vec.back() < elem){
        vec.push_back(vec.back() + vec[vec.size() - 2]);
    }
    if(vec.back() == elem)
        return true;
    else
        return false;
}

int main(){
    int arr[6] = {1, 1, 2, 3, 5, 8};
    vector<int> svec(arr, arr + 6);
    cout << "查询元素是否属于斐波那契数列中的元素\n请输入元素：";
    int num;
    cin >> num;
    cout << is_elem(svec,num) << endl;
    return 0;
}