#include <iostream>
using namespace std;

class Number{
private:
	int res;
public:
	Number(const int& res);
	Number& add(const int& op);
	Number& sub(const int& op);
	void print();
};

Number::Number(const int& res){
	this->res = res;
}
Number& Number::add(const int& op){
	this->res += op;
	return *this;
}
Number& Number::sub(const int& op){
	this->res -= op;
	return *this;
}
void Number::print(){
	cout << this->res << endl;
}