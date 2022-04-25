#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename IteratorType, typename elemType>
IteratorType
find(IteratorType first, IteratorType last, const elemType &value){
    for( ; first != last; first++ )
        if(value == *first)
            return first;
    return last;
}

int main(){
    const int asize = 8;
    int ia[asize] = { 1, 1, 2, 3, 5, 8, 13, 21};
    int first, second, third;

    vector<int> ivec(ia, ia + asize);
    list<int> ilist(ia, ia +asize);

    for(int i= 0; i!= asize ;i++)
        cout << ia[i] << ' ';
    cout << endl;

    cout << "输入查找的第一个元素：";
    cin >> first;
    int *pia = find(ia, ia + asize, first);
    if(pia != ia + asize)
        cout << first << " 找到了\n";
    else
        cout << first << " 没找到\n";
    
    cout << "输入查找的第二个元素：";
    cin >> second;
    vector<int>::iterator it;
    it = find(ivec.begin(),ivec.end(),second);
    if(it != ivec.end())
        cout << second << " 找到了\n";
    else
        cout << second << " 没找到\n";

    cout << "输入查找的第三个元素：";
    cin >> third;
    list<int>::iterator iter;
    iter = find(ilist.begin(),ilist.end(),third);
    if(iter != ilist.end())
        cout << third << " 找到了\n";
    else
        cout << third << " 没找到\n";
    
    return 0;
}