#include <iostream>
using namespace std;

class Base {
	public:
		virtual void print() {
			cout << "Base" << endl;
		}
		virtual ~Base() {
			cout << "Base destruct" << endl;
		}
};
class Derived : public Base {
	public:
		void print() {
			cout << "Derived" << endl;
		}
		~Derived() {
			cout << "Derived destruct" << endl;
		}
};

int main() {
	Base b1;
	Derived d1;
	Base *pTest1 = new Base;
	Base *pTest2 = new Derived;
	pTest2->print();
	pTest1->print();
	b1.print();
	d1.print();
	delete pTest1;
	delete pTest2;
	b1 = d1;
	b1.print();
	return 0;
}
