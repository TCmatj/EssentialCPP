#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ifstream infile("exe1.7.txt");
    if(!infile)
        cerr << "无法打开文件";
    vector<string> svec;
    string str;
    while(infile >> str){
        svec.push_back(str);
        cout << str <<' ';
    }
    sort(svec.begin(),svec.end());
    ofstream outfile("exe1.7.out.txt",ios_base::app);
    if(!outfile)
        cerr << "无法打开文件"; 
    for(int i = 0;i < svec.size();i++){
        outfile << svec[i] << endl;
    }
    return 0;
}