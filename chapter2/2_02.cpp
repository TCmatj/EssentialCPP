#include <iostream>
#include <vector>
using namespace std;

bool fibon_elem(int, int &);
bool print_sequence(int);

int main(){
    int pos;
    bool flag = true;    //是否继续输入
    char again;

    while(flag){
        cout << "Please enter your a position: ";
        cin >> pos;

        int elem;
        if(fibon_elem(pos,elem))
            cout << "element # " << pos
                 << " is " << elem << endl;
        else
            cout << "Sorry. Could not calculate element # "
                 << pos << endl;
        print_sequence(pos);

        cout << "Try again?Y/N\n";
        cin >> again;
        if(again == 'N' || again == 'n')
            flag = false;
    }
    return 0;
}

bool is_size_ok(int size){
    const int max_size = 1024;
    if(size <= 0 || size > max_size){
        cerr << "Oops:request size is not supported: "
             << size << " -- can't fulfill request.\n";
             return false;
    }
    return true;
}

const vector<int>* fibon_seq(int size){
    //计算斐波那契数列中的size个元素，返回持有这些元素的静态容器的地址
    const int max_size = 1024;
    static vector<int> elems;
    if(!is_size_ok(size))
        return 0;
    for(int ix = elems.size(); ix < size; ix++){
        if(ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
    }
    return &elems;
}

inline bool fibon_elem(int pos, int &elem){
    const vector<int>* pseq = fibon_seq(pos);
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos -1];
    return true;
}

bool print_sequence(int pos){
    if(pos <= 0 || pos > 1024){
        cerr << "invaild position: " << pos
             << " -- cannot handle request!\n";
        return 0;
    }

    cout << "The Fibonacci Sequence for "
         << pos << " position: \n\t";
    
    switch(pos){
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }
    int elem;
    int n_2 = 1, n_1 = 1;
    for (int ix = 3;ix <= pos; ix++){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
        cout << elem << (!(ix % 10)?"\n\t":" ");
    }
    cout << endl;

    return true;
}