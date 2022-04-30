#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Stack{
    //此stack的元素被存储于名为_stack的string vector内
    public:
        //任何操作函数成功都返回true
        //pop和peek会将字符串内容置于elem内
        bool push(const string&);
        bool pop(string &elem);
        bool peek(string &elem);

        bool empty();
        bool full();

        int size(){
            return _stack.size();
        };

    private:
        vector<string> _stack;
};

inline bool 
Stack::empty(){
    return _stack.empty();
}

inline bool
Stack::full(){
    return _stack.size() == _stack.max_size();
}
