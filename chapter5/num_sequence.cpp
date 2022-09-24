#include "num_sequence.h"

bool num_sequence::check_integrity(int pos, int size) const{
    if(pos <= 0||pos > _max_elems){
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
	if(pos > size)
			//通过虚拟机制调用
			gen_elems(pos);
    return true;
}

ostream& operator<<(ostream &os, const num_sequence &ns){
    return ns.print(os);
}
