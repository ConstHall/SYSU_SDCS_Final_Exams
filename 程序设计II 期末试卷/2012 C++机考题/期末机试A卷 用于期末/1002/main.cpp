#include <iostream>
#include <stdio.h>
#include "source.cpp"
using namespace std;

int main(){
	LinkList l(10);

	l.print();//���1 2 3 
	cout << l.getSize() << endl;//���3

	cout << l.delNode(1) << endl;//���1
	l.print();//���2 3 
	cout << l.getSize() << endl;//���2

	cout << l.getNodeData(3) << endl;//���2
	cout << l.getSize() << endl;//���2


	cout << l.delNode(4) << endl;//���-1
	l.print();//���2 3 
	cout << l.getSize() << endl;//���2
	
	cout << l.delNode(1) << endl;//���2
	l.print();//���3
	cout << l.getSize() << endl;//���1
	
	cout << l.delNode(-1) << endl;//���3
	l.print();//�������
	cout << l.getSize() << endl;//���0

	return 0;
}