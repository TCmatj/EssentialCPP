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
    int str, sval;

    list<int> ilist(ia, ia +asize);
    list<int>::iterator first = ilist.begin(),
                        last = ilist.end();

    for(int i= 0; i!= asize ;i++)
        cout << ia[i] << ' ';
    cout << endl << "输入要删除元素的范围,first:";
    cin >> str;
    cout << " last:";
    cin >> sval;

    list<int>::iterator it1 = find(first,last,str);
    list<int>::iterator it2 = find(first,last,sval);
    ilist.erase(it1, it2);

    for(list<int>::iterator i = ilist.begin(); i!= ilist.end() ;i++)
        cout << *i << ' ';
    cout << endl;

    return 0;
}