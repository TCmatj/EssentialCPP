#include "LessThan.h"
using namespace std;

int count_less_than(const vector<int> &vec, int comp){
    //返回vec中小于comp的数据个数
    LessThan lt(comp);      //初始化
    
    int count = 0;
    for(int ix=0;ix<vec.size();ix++)
        if(lt(vec[ix]))
            count++;
    return count;
}

void print_less_than(const vector<int> &vec,int comp,ostream &os){
    //默认值只能指定一次，在函数声明或定义，不能全给指定了，这是默认参数值的提供的两个规则之一
    //输出小于comp的vec元素
    LessThan lt(comp);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator it_end = vec.end();

    os << "elements less than " << lt.comp_val() << endl;
    while((iter=find_if(iter,it_end,lt))!=it_end){
        os << *iter << ' ';
        iter++;
    }
}