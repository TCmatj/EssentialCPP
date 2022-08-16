#include "Triangular.h"

bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const{
    return _index == rhs._index;
}

bool Triangular_iterator::
operator!=(const Triangular_iterator &rhs) const{
    return !(*this == rhs);
}

int Triangular_iterator::
operator*() const{
//    check_integrity();
    return Triangular::_elems[_index];  //在Triangular.h中包含此头文件，并使用friend机制
}

Triangular_iterator& Triangular_iterator::
operator++(){
    //前置版本
    ++_index;
    //check_integrity();
    return *this;
}

Triangular_iterator Triangular_iterator::
operator++(int){
    //后置版本,重载规则要求参数列表必须独一无二，因此需要一个int参数
    Triangular_iterator tmp = *this;
    ++_index;
    //check_integrity();
    return tmp;
}

// inline void Triangular_iterator::
// check_integrity() const{
//     //第七章
//     if(_index >= Triangular::_max_elems)
//         throw iterator_overflow();

//     if(_index >= Triangular::_elems.size())
//         Triangular::gen_elements(_index+1);
// }
