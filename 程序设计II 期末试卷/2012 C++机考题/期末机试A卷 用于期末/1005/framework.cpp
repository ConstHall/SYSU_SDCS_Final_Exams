#include <iostream> 
using namespace std;
#include "source.cpp"

void fn1(int);
unsigned int * fn2();
void fn3(unsigned int *,int);

unsigned int * fn2()
{
    unsigned int *n = new unsigned int;
    if (n == 0)
        throw OutOfMemory();
    return n;
}

void fn1(int num)
{
    unsigned int *p = fn2();

    fn3(p,num);
    cout << "The number is : " << *p << endl;
    delete p;
}

void fn3(unsigned int *p,int num)
{
    long Number;
    Number=num;

    if (Number > 1000 || Number < 0)
        throw RangeError(Number);
    *p = Number;
}

int main()
{
    freopen("Exception.out","w",stdout);
    try
    {
        fn1(56);
    }

    catch (Exception& theException)
    {
        theException.PrintError();
    }

    try
    {
        fn1(2000);
    }

    catch (Exception& theException)
    {
        theException.PrintError();
    }
    return 0;
}
