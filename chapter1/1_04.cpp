#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string name,nametemp;
    int num_tries;
    int num_rights;
    ifstream infile("1_03.txt");

    cout << "Enter your name: ";
    cin >> name;

    if(!infile){
        cerr << "Oops, unable to save session data!" << endl;
    }
    else{
        while(1){
            infile >> nametemp >> num_tries>> num_rights; 
            if( name == nametemp ) break;
        }

        cout << "tries: " << num_tries << endl;
        cout << "rights: " << num_rights << endl;
    }

    return 0;
}