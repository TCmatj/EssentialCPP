#include<iostream>
using namespace std;

//v1.0
// class num_sequence{
//     public:
//         int             elem(int pos);                  //返回pos位置上的元素
//         void            gen_elems(int pos);             //产生知道pos位置的所有元素
//         const char*     what_am_i() const;              //返回确切的数据类型
//         ostream&        print(ostream &os=cout) const;  //将所有元素写入os
//         bool            check_integrity(int pos);       //检查pos是否为有效位置
//         static int      max_elems();                    //返回所支持的最大位置值
// };

//v2.0
//class num_sequence{
//    public:
//        virtual ~num_sequence(){};
//
//        virtual int             elem(int pos) const=0;                  		 //返回pos位置上的元素
//        virtual const char*     what_am_i() const=0;                    		 //返回确切的数据类型
//        virtual ostream&        print(ostream &os=cout) const=0;        		 //将所有元素写入os
//        static int              max_elems(){return _max_elems;}        			 //返回所支持的最大位置值
//   		friend ostream& 		operator<<(ostream&os,const num_sequence &ns);
//
//    protected:
//        virtual void            gen_elems(int pos) const=0;          			 //产生知道pos位置的所有元素
//        bool                    check_integrity(int pos, int size) const;        //检查pos是否为有效位置
//
//        const static int        _max_elems = 1024;
//};

//v3.0
class num_sequence2{
		public:
				virtual				 	~num_sequence(){}
				virtual const char* 	what_am_i() const=0;
				int						elem(int pos) const;
				ostream&				print(ostream &os=cout) const;
				
				int 					length() const  { return _length; }
				int 					beg_pos() const { return _beg_pos; }
				static int 				max_elems()		{ return 64;}

		protected:
				virtual void			gen_elems(int pos) const=0;
				bool 					check_integrity(int pos, int size) const;

				num_sequence( int len, int bp, vector<int> &re)
						:_length( len ), _beg_pos( bp ), _relems( re ){}

				int						_length;
				int 					_beg_pos;
				vector<int>				&_relems;
};

