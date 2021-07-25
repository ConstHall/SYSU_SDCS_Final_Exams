#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Calculator
{
public:
	Calculator(){};
	int getResult(string);
private:
	bool can_do(char c);
	void exe_cacu();
	void set(string);
	string exp;
	stack<int> number;
	stack<char> op;
};
void Calculator::set(string s)
{
	exp = s;
	while(!number.empty())	number.pop();
	while(!op.empty()) op.pop();
}
bool Calculator::can_do(char c)
{
	if(op.empty()) return false;
	if(op.top() == '(')	return false;
	if(c == '+' || c == '-')	return true;
	if(c == '*' && (op.top() == '*' || op.top() == '/'))	return true;
	if(c == '/' && (op.top() == '*' || op.top() == '/'))	return true;
	return false;
}

void Calculator::exe_cacu()
{
	int b = number.top();
	number.pop();
	int a = number.top();number.pop();
	int result;
	switch(op.top())
	{
	case '+':
		result = a+b;
		break;
	case '-':
		result = a-b;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		result = a/b;
		break;
	}
	number.push(result);
	op.pop();
}


int Calculator::getResult(string s)
{
	set(s);
	int temp = 0;
	for(unsigned int i=0; i<exp.length(); i++)
	{
		if(isdigit(exp[i]))
		{
			temp = temp*10 + exp[i]-'0';
			if(i+1 == exp.length() || !isdigit(exp[i+1]))
			{
				number.push(temp);
				temp = 0;
			}
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if(can_do(exp[i]))
				exe_cacu();
			op.push(exp[i]);
		}
		else if(exp[i] == '(')
			op.push(exp[i]);
		else
		{
			while(op.top() != '(')
				exe_cacu();
			op.pop();
		}
	}
	while(!op.empty())
		exe_cacu();

	return number.top();
}