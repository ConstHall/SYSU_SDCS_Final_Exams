#include <iostream>
#include <string>
#include "source.cpp"
using namespace std;

int main()
{
	Calculator c;
	cout<<c.getResult("1+2+3")<<endl;
	cout<<c.getResult("((3+4)*5+6)*7")<<endl;
	cout<<c.getResult("1+2*3")<<endl;
	cout<<c.getResult("2*5+10")<<endl;
	cout<<c.getResult("3*(5+4)")<<endl;
	cout<<c.getResult("(4+5)*(2+2)")<<endl;
	cout<<c.getResult("1/2+1/2")<<endl;
	cout<<c.getResult("0+0")<<endl;
	cout<<c.getResult("4*5-7*8")<<endl;
	cout<<c.getResult("378+456-500*12/2")<<endl;
	cout<<c.getResult("((11*(12+13)*(14+15))+(16+17))*(18+19)")<<endl;
	cout<<c.getResult("4+5")<<endl;
	cout<<c.getResult("4")<<endl;
	cout<<c.getResult("77+44-22*33/11")<<endl;
	return 0;
}