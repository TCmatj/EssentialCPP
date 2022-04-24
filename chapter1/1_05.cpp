#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string name,nametemp;
    int num_tries;
    int num_rights;
    fstream iofile("data.txt",ios_base::in | ios_base::app);

    cout << "Enter your name: ";
    cin >> name;
    cout <<"Enter your num_tries, num_rights: ";
    cin >> num_tries >> num_rights;
    if(!iofile){
        cerr << "Oops, unable to save session data!" << endl;
    }
    else{
        iofile.seekg(0);    //定位到文件开头
        iofile << name << ' ' << num_tries << ' ' << num_rights <<endl;
        iofile.seekg(0);    //定位到文件开头
        iofile >> nametemp >> num_tries>> num_rights;
        cout << "tries: " << num_tries << endl;
        cout << "rights: " << num_rights << endl;
    }

    return 0;
}