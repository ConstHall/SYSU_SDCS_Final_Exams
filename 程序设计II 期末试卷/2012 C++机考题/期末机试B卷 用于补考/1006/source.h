#include <string>
#include <iostream>
using namespace std;

class Person{
public:
	Person(){ cout << "Construct Person" << endl;}
	~Person(){ cout << "Destruct Person" << endl;}
public:
	string name;//����
	int sex;//1��ʾ�� 0��ʾŮ
};

class Student:virtual public Person{
public:
	Student(){ cout << "Construct Student" << endl;}
	~Student(){ cout << "Destruct Student" << endl;}
public:
	string sno;//ѧ��
};

class Worker:virtual public Person{
public:
	Worker(){ cout << "Construct Worker" << endl;}
	~Worker(){ cout << "Destruct Worker" << endl;}
public:
	string wno;//ְ����
};

class InService:public Student, public Worker{
public:
	InService(){ cout << "Construct InService" << endl;}
	~InService(){ cout << "Destruct InService" << endl;}
};
