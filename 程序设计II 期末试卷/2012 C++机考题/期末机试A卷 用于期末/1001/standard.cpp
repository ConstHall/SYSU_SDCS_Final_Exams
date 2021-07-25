#include <iostream>
using namespace std;

class Base
{
public:
    Base() {};
    virtual ~Base() {cout<<"Base destruct"<<endl;}
    virtual void print() {cout<<"Base"<<endl;}
};

class Derived : public Base
{
public:
    Derived() {};
    ~Derived() { cout<<"Derived destruct"<< endl; }; 
    void print() { cout <<"Derived"<< endl; };
};