#include <iostream>
#include "source.cpp"
using namespace std;

int main(){
	InService is;

	is.name = "name";
	is.sex = 0;
	is.sno = "10390000";
	is.wno = "10990000";

	cout << ((Person*)(&is))->name << endl;
	cout << ((Person*)(&is))->sex << endl;
	cout << ((Student*)(&is))->name << endl;
	cout << ((Student*)(&is))->sex << endl;
	cout << ((Student*)(&is))->sno << endl;
	cout << ((Worker*)(&is))->name << endl;
	cout << ((Worker*)(&is))->sex << endl;
	cout << ((Worker*)(&is))->wno << endl;
	return 0;
}