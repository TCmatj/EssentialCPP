#include "BTnode.h"

template <typename valType>
inline BTnode<valType>::
BTnode( const valType &val)
: _val(val){
    _cnt = 1;
    _lchild = _rchild = 0;
}