#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int usr_val;
    int num_tries = 0, num_right(0);//构造函数法
    double usr_score(0.0);
    char usr_rsp;
    char try_again;
    bool next_seq = true;              //显示下一组数列
    bool next_rsp = true;              
    bool go_for_it = true;             //用户想继续猜一次
    bool got_it = false;               //用户是否猜对
    const int max_tries = 3;           //最大猜测次数
    
    const int seq_size = 18;           //数组大小
    const int max_seq = 6;
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    int elem_vals[seq_size] = {
        1, 2, 3,    //Fibonacci
        3, 4, 7,    //Lucas
        2, 5, 12,   //Pell
        3, 6, 10,   //Triangular
        4, 9, 16,   //Square
        5, 12, 22   //Pentagonal
    };
    vector<int> elem_seq( elem_vals, elem_vals + seq_size );
    int cur_tuple = 0;

    while(next_seq == true){
        
        //显示数列的前两个数字
        cout << "The first 2 elements of the sequence are:"
             << elem_seq[cur_tuple] << ',' << elem_seq[cur_tuple + 1]
             << "\nWhat is the next element?";
        int next_elem = elem_seq[cur_tuple + 2];

        int tries_cnt = 0;             //对每个数列的猜测次数
        next_seq = true;
        go_for_it = true;
        got_it = false;

        while((!got_it) && go_for_it && ((tries_cnt++) <= max_tries)){
            int usr_guess;
            cin >> usr_guess;
            num_tries++;
            if(usr_guess == next_elem){
                //如果答案正确
                cout << "Very good. Yes, "
                     << elem_seq[cur_tuple + 2]
                     << " is the next element in the "
                     <<seq_names[cur_tuple / 3] 
                     << " sequence.\n";
                got_it = true;
                num_right++;
                tries_cnt++;
            }
            else{
                switch (tries_cnt){
                case 1:
                    cout << "Oops! Nice guess but not quite it.\n";
                    break;
                case 2:    
                    cout << "Hmm. Sorry. Wrong a second time.\n";
                    break;
                case 3:    
                    cout << "Ah, this is harder than it looks, isn't it?\n";
                    break;
                default:
                    cout << "It must be getting pretty frustating by now!\n";
                    break;
                }
                cout << "Try another sequence?Y/N?";
                cin >> usr_rsp;
                if (usr_rsp == 'N' || usr_rsp == 'n')
                    go_for_it = false;
            }//else
        }//while
        cout << "Want to try another sequence?(Y/N)" << endl;
        cin >> try_again;
        if (try_again == 'N' || try_again == 'n')
            next_seq = false;
        else {
            cur_tuple += 3;
            cur_tuple %= 18;
        }//else
    }//while

    return 0;
}