#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class LessThan{
    public:
        LessThan( int val ) :_val( val ) {}
        int  comp_val() const    { return _val; } //基值的读取
        void comp_val( int nval ){ _val = nval; } //基值的写入

        bool operator()(int _value) const;

    private:
        int _val;
};

inline bool LessThan::operator()(int value) const{
    return value < _val;
}

//非成员函数的声明
int count_less_than(const vector<int> &vec, int comp);
void print_less_than(const vector<int> &vec,int comp,ostream &os=cout);