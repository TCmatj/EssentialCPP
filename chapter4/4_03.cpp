#include <vector>
#include "LessThan.h"
using namespace std;

int main(){
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14, 
                   23, 67, 9, 0, 27, 55, 8, 16,};
    vector<int> vec(ia,ia+16);
    int comp_val = 20;

    cout << "Number of elements less than "
         << comp_val << " are "
         << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val);

    system("pause");
    return 0;
}