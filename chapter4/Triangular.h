#include <iostream>
#include <string>
using namespace std;

class Triangular{
    public:
        Triangular();
        Triangular(int len);
        Triangular(int len = 1, int bp = 1);
    

    private:
        string _name;
        int _length;    //元素个数
        int _beg_pos;   //起始位置
        int _next;      //下一个迭代目标

};
Triangular::Triangular(){
    //默认的构造函数
    _length = 1;
    _beg_pos = 1;
    _next = 0;
}
Triangular::Triangular(int len, int bp)
    : _name("Triangular")
{
    //不要相信“用户永远是对的”
    //由于提供了默认值，可以同时支持原来的三个版本
    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp :1;
    _next = _beg_pos - 1;
}