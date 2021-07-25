#include <string>
#include <iostream>
using namespace std;

class Person{
public:
	Person(){ cout << "Construct Person" << endl;}
	~Person(){ cout << "Destruct Person" << endl;}
public:
	string name;//姓名
	int sex;//1表示男 0表示女
};

class Student:virtual public Person{
public:
	Student(){ cout << "Construct Student" << endl;}
	~Student(){ cout << "Destruct Student" << endl;}
public:
	string sno;//学号
};

class Worker:virtual public Person{
public:
	Worker(){ cout << "Construct Worker" << endl;}
	~Worker(){ cout << "Destruct Worker" << endl;}
public:
	string wno;//职工号
};

class InService:public Student, public Worker{
public:
	InService(){ cout << "Construct InService" << endl;}
	~InService(){ cout << "Destruct InService" << endl;}
};
