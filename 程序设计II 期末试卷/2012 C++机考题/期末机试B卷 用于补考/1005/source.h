#include <iostream>
#include <stdio.h>
using namespace std;

class Complex{
private:
	double real, imag;
public:
	Complex(const double& real = 0.0, const double& imag = 0.0);
	Complex(const Complex& otherComplex);

	Complex operator + (const Complex& otherComplex);
	Complex operator - (const Complex& otherComplex);
	Complex operator * (const Complex& otherComplex);
	Complex operator / (const Complex& otherComplex);//除法不考虑分母为0的情况

	Complex& operator = (const Complex& otherComplex);
	Complex& operator += (const Complex& otherComplex);
	Complex& operator -= (const Complex& otherComplex);
	Complex& operator *= (const Complex& otherComplex);
	Complex& operator /= (const Complex& otherComplex);//除法不考虑分母为0的情况


	//实部虚部各自加1
	Complex& operator++();//前置++
	Complex operator++(int n);//后置++

	//实部虚部各自减1
	Complex& operator--();//前置--
	Complex operator--(int n);//后置--

	bool operator == (const Complex& otherComplex);
	bool operator != (const Complex& otherComplex);


	/*
	 *	当real = 0, image = -1的时候按照习惯理应输出： -j，还有负数等等问题
	 *	为了简化问题，我们这里不考虑输出格式问题，直接打印0.0000 + j-1.0000即可（小数一定保留4位！注意加号旁边有空格有换行！）
	 *	有关以上提到的格式输出，大家可以课下自己思考！
	 */
	void print();
};


Complex::Complex(const double& real, const double& imag){
	this->real = real;
	this->imag = imag;
}
Complex::Complex(const Complex& otherComplex){
	this->real = otherComplex.real;
	this->imag = otherComplex.imag;
}

Complex Complex::operator + (const Complex& otherComplex){
	return Complex(real+otherComplex.real, imag+otherComplex.imag);
}
Complex Complex::operator - (const Complex& otherComplex){
	return Complex(real-otherComplex.real, imag-otherComplex.imag);
}
Complex Complex::operator * (const Complex& otherComplex){
	return Complex(real*otherComplex.real - imag*otherComplex.imag,
		real*otherComplex.imag + imag*otherComplex.real);
}
Complex Complex::operator / (const Complex& otherComplex){
	double deno = otherComplex.real*otherComplex.real + otherComplex.imag*otherComplex.imag;

	return Complex(
					(real*otherComplex.real + imag*otherComplex.imag) / deno, 
					(imag*otherComplex.real - real*otherComplex.imag) / deno
					);
}

Complex& Complex::operator = (const Complex& otherComplex){
	this->real = otherComplex.real;
	this->imag = otherComplex.imag;

	return *this;
}

Complex& Complex::operator += (const Complex& otherComplex){
	real += otherComplex.real;
	imag += otherComplex.imag;
	return *this;
}
Complex& Complex::operator -= (const Complex& otherComplex){
	real -= otherComplex.real;
	imag -= otherComplex.imag;
	return *this;
}
Complex& Complex::operator *= (const Complex& otherComplex){
	double tmpR = real, tmpI = imag;

	real = tmpR * otherComplex.real - tmpI * otherComplex.imag;
	imag = tmpR * otherComplex.imag + tmpI * otherComplex.real;
	return *this;
}
Complex& Complex::operator /= (const Complex& otherComplex){
	double deno = otherComplex.real*otherComplex.real + otherComplex.imag*otherComplex.imag;
	double tmpR = real, tmpI = imag;

	real = (tmpR*otherComplex.real + tmpI*otherComplex.imag) / deno; 
	imag = (tmpI*otherComplex.real - tmpR*otherComplex.imag) / deno;

	return *this;
}

Complex& Complex::operator++(){//前置++
	real++;
	imag++;
	return *this;
}
Complex Complex::operator++(int n){//后置++
	Complex tmp = *this;
	real++;
	imag++;
	return tmp;
}

Complex& Complex::operator--(){//前置--
	real--;
	imag--;
	return *this;
}

Complex Complex::operator--(int n){//后置--
	Complex tmp = *this;
	real--;
	imag--;
	return tmp;
}

bool Complex::operator == (const Complex& otherComplex){
	return real == otherComplex.real && imag == otherComplex.imag;
}
bool Complex::operator != (const Complex& otherComplex){
	return !this->operator ==(otherComplex);
}

void Complex::print(){
	printf("%.4lf + j%.4lf\n", real, imag);
}