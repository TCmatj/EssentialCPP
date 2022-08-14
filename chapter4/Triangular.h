#include <iostream>
#include <vector>
#include <string>
#include "Triangular_iterator.h"
using namespace std;

class Triangular{
    friend class Triangular_iterator;       //friend机制
    public:
        typedef Triangular_iterator iterator;//嵌套类型

        Triangular_iterator begin() const{
            return Triangular_iterator(_beg_pos);
        }
        Triangular_iterator end() const{
            return Triangular_iterator(_beg_pos+_length);
        }

        Triangular(int len = 1, int bp = 1);
        static bool is_elem(int);
        static void gen_elements(int length);
        static void gen_elems_to_value(int value);
        static void display(int length,int beg_pos,ostream &os = cout);
        //以下是 const member function
        int length()            const { return _length;  }
        int beg_pos()           const { return _beg_pos; }
        int elem( int pos )     const;
        //以下是 non-const member function
        bool next( int &val );
        void next_reset () { _next = _beg_pos -1; }
        Triangular& copy( const Triangular &rhs );

    private:
        string _name;
        int _length;    //元素个数
        int _beg_pos;   //起始位置
        mutable int _next;      //下一个迭代目标
        
        static const int _max_elems = 1024;
        static vector<int> _elems;
};