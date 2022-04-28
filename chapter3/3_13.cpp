#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream in_file("input_file.txt");     //与3_12区别
    ofstream out_file("output_file.txt");   //与3_12区别

    if(!in_file || !out_file){              //与3_12区别
        cerr << "无法打开文件\n";            //与3_12区别
        return -1;                          //与3_12区别
    }                                       //与3_12区别

    istream_iterator<string> is(in_file);   //与3_12区别
    istream_iterator<string> eof;
    
    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(out_file,"\n");  //与3_12区别
    copy(text.begin(), text.end(), os);
    //cout << endl;
}