#include <iostream>
#include "source.cpp"
using namespace std;

int main(){

	Number n(1);
	n.add(2).sub(3).add(4);
	n.print();

	
	Number n1(-1);
	n1.sub(12).sub(3).sub(4);
	n1.print();

	
	Number n2(0);
	n2.add(-13).add(0).add(0);
	n2.add(13);
	n2.print();

	return 0;
}