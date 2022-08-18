#include "Triangular.h"
#include "Triangular_iterator.h"

vector<int> Triangular::_elems;         //static data member只有唯一实体,必须在cpp中提供清楚的定义

Triangular::Triangular(int len, int bp)
    : _name("Triangular"),
    _length(len > 0 ? len : 1),
    _beg_pos(bp > 0 ? bp :1)
{
    //不要相信“用户永远是对的”
    //由于提供了默认值，可以同时支持原来的三个版本
    _next = _beg_pos - 1;
    int elem_cnt = _beg_pos + _length - 1;

    if( _elems.size() < elem_cnt )
        gen_elements( elem_cnt );
}

int sum( const Triangular &train){
    int beg_pos = train.beg_pos();
    int length = train.length();
    int sum = 0;
    for(int ix = 0;ix < length; ix++){
        sum += train.elem( beg_pos + ix);
    }
    return sum;
}

//判断给定元素是否存在
bool Triangular::is_elem(int val){
    if(val < 0)
        return false;
    Triangular tri(1,1024);
    for(int i = 0;i < 1024;i++)
        if(val == _elems[i])
            return true;
    return false;
}

//添加为指定长度
void Triangular::gen_elements(int length){
    if(length < 0||length > _max_elems){
        cerr << "范围错误\n";
        return;
    }
    if( _elems.size() < length){
        int ix = _elems.size() ? _elems.size()+1 : 1;//从数组大小的下一个开始加入数组
        for( ; ix <= length;ix++)
            _elems.push_back(ix*(ix+1)/2);
    }
}

//添加元素至_elems，直到到达value值
void Triangular::gen_elems_to_value(int value){
    int ix = _elems.size();
    if(!ix){
        _elems.push_back(1);
        ix = 1;
    }
    while(_elems[ix - 1] < value && ix < _max_elems){
        //cout << "elems to value:" << ix*(ix+1)/2 << endl;
        ix++;
        _elems.push_back( ix*(ix+1)/2 );
    }
    if(ix == _max_elems)
        cerr << "Triangular Sequence: oops: value too large "
             << value << " -- exceeds max size of "
             << _max_elems << endl;
}

//返回第pos个元素的值
int Triangular::elem( int pos ) const{
    //在主体之外定义的成员函数，必须在声明与定义处都指定const
    return _elems[ pos - 1 ];
}

Triangular& Triangular::copy( const Triangular &rhs ){
    //检查两个对象是否相同
    if ( this != &rhs ){
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos - 1;
    }
    return *this;
}

//若下一个位置合法，则将值传递出去，并将_next加一
bool Triangular::next( int &value ){
    if( _next < _beg_pos + _length - 1 ){
        value = _elems[ _next++ ];
        return true;
    }
    return false;
}

ostream& operator<<(ostream &os,const Triangular &rhs){
    os << "(" << rhs.beg_pos() << ", "
       << rhs.length() << " )";

    //rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

istream& operator>>(istream &is,Triangular &rhs){
    char ch1,ch2;
    int bp,len;
    
    //假设输入为(3,6) 6 10 15 21 28 36
    //那么ch1 == '(' ，bp == 3，ch2 == ')'，len == 6
    is >> ch1 >> bp >> ch2 >> len;

    //设定rhs的三个数据成员
    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();

    return is;
}