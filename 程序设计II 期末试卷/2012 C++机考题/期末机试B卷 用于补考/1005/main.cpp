#include <iostream>
#include "source.cpp"

using namespace std;

int main()
{
	Complex a(1.0, 2.0), b(2.0, 3.0);
	Complex c;

	c.print();

	c = a + b;
	c.print();

	
	c = a - b;
	c.print();

	
	c = a * b;
	c.print();

	
	c = a / b;
	c.print();

	
	c = a;
	c += b;
	c.print();
	
	c = a;
	c -= b;
	c.print();

	c = a;
	c *= b;
	c.print();

	c = a;
	c /= b;
	c.print();

	c = a++;
	a.print();
	c.print();

	
	c = ++a;
	a.print();
	c.print();

	
	c = a--;
	a.print();
	c.print();

	
	c = --a;
	a.print();
	c.print();

	c = a;
	if (c == a)
		cout << "c == a" << endl;
	
	if (c == b)
		cout << "c == b" << endl;

    return 0;
}

