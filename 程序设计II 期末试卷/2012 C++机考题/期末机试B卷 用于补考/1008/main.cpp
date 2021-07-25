#include <iostream>
#include "source.cpp"
using namespace std;

int main(){
	cout << gt(1, 2) << endl;
	cout << gt(2, 1) << endl;
	cout << gt(1.1, 2.1) << endl;
	cout << gt(2.1, 1.1) << endl;

	int a = 1, b = 2;
	int *pta = &a, *ptb = &b;

	cout << gt(pta, ptb) << endl;
	a = 2, b = 1;
	cout << gt(pta, ptb) << endl;
	a = 3, b = 4;
	cout << gt(pta, ptb) << endl;

	cout << gt("abc", "cdf") << endl;
	
	cout << gt("cdf", "abc") << endl;
	
	cout << gt("abc", "abc") << endl;

	return 0;
}