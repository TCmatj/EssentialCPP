#include <iostream>
#include "Fibonacci.h"
using namespace std;

int main(){
		Fibonacci fib;

		cout << "fib:beginning at element 1 for 1 element: " << endl;
		fib.print();

		Fibonacci fib2(16);
		cout << "\nfib2:beginning at element 1 for 16 element: " << endl;
		fib2.print();

		Fibonacci fib3(8,12);
		cout << "\nfib3:beginning at element 12 for 8 element: " << endl;
		fib3.print();
		return 0;
}

