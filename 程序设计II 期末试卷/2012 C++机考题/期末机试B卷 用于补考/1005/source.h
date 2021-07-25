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
	Complex operator / (const Complex& otherComplex);//���������Ƿ�ĸΪ0�����

	Complex& operator = (const Complex& otherComplex);
	Complex& operator += (const Complex& otherComplex);
	Complex& operator -= (const Complex& otherComplex);
	Complex& operator *= (const Complex& otherComplex);
	Complex& operator /= (const Complex& otherComplex);//���������Ƿ�ĸΪ0�����


	//ʵ���鲿���Լ�1
	Complex& operator++();//ǰ��++
	Complex operator++(int n);//����++

	//ʵ���鲿���Լ�1
	Complex& operator--();//ǰ��--
	Complex operator--(int n);//����--

	bool operator == (const Complex& otherComplex);
	bool operator != (const Complex& otherComplex);


	/*
	 *	��real = 0, image = -1��ʱ����ϰ����Ӧ����� -j�����и����ȵ�����
	 *	Ϊ�˼����⣬�������ﲻ���������ʽ���⣬ֱ�Ӵ�ӡ0.0000 + j-1.0000���ɣ�С��һ������4λ��ע��Ӻ��Ա��пո��л��У���
	 *	�й������ᵽ�ĸ�ʽ�������ҿ��Կ����Լ�˼����
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

Complex& Complex::operator++(){//ǰ��++
	real++;
	imag++;
	return *this;
}
Complex Complex::operator++(int n){//����++
	Complex tmp = *this;
	real++;
	imag++;
	return tmp;
}

Complex& Complex::operator--(){//ǰ��--
	real--;
	imag--;
	return *this;
}

Complex Complex::operator--(int n){//����--
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