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

int main(){
    int arr[6] = {1, 2, 5, 8, 11, 12};
    vector<int> svec(arr, arr + 6);
    cout << is_elem(svec,14) << endl;
    return 0;
}