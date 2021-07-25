#include <iostream>
#include <stdio.h>
#include "source.cpp"
using namespace std;

int main(){
	LinkList l(10);

	l.print();//输出1 2 3 
	cout << l.getSize() << endl;//输出3

	cout << l.delNode(1) << endl;//输出1
	l.print();//输出2 3 
	cout << l.getSize() << endl;//输出2

	cout << l.getNodeData(3) << endl;//输出2
	cout << l.getSize() << endl;//输出2


	cout << l.delNode(4) << endl;//输出-1
	l.print();//输出2 3 
	cout << l.getSize() << endl;//输出2
	
	cout << l.delNode(1) << endl;//输出2
	l.print();//输出3
	cout << l.getSize() << endl;//输出1
	
	cout << l.delNode(-1) << endl;//输出3
	l.print();//输出空行
	cout << l.getSize() << endl;//输出0

	return 0;
}