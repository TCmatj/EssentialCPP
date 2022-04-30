#include <iostream>
#include <vector>
#include "Stack.h"
using namespace std;

void fill_stack(Stack &stack,istream &is=cin){
    string str;
    while(is>>str && !stack.full())
        stack.push(str);
    
    cout << "Read in " << stack.size() << " elements\n";

}

int main(){
    Stack st;
    string elem;
    st.push("adsd");

    st.pop(elem);
    cout << elem << endl;

    st.push("ahf00");
    st.push("Sfa");
    
    st.peek(elem);
    cout << elem << endl;

    cout << "Size: " << st.size() << endl;
    fill_stack(st);
    cout << "Size: " << st.size() << endl;
    
}