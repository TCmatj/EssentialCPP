#include "num_sequence.h"
#include <vector>
#include <iostream>
using namespace std;

//必须为每一个纯虚函数提供对应的实现
class Fibonacci2:public num_sequence2{
		public:
			Fibonacci2(int len=1, int beg_pos=1);
			Fibonacci2(const Fibonacci2 &rhs);
			virtual const char* what_am_i() const{ return "Fibonacci";}

		protected:
			virtual void		gen_elems(int pos) const;
			static vector<int>  _elems;
};

Fibonacci(int len, int beg_pos)
		: num_sequence(len, beg_pos, _elems)
{}

Fibonacci2(const Fibonacci2 &rhs)
		: num_sequence(rhs)
{}

Fibonacci& Fibonacci::
operator=(const Fibonacci &rhs){
		if(this != &rhs)
				num_sequence::operator=(rhs);

		return *this;
}

