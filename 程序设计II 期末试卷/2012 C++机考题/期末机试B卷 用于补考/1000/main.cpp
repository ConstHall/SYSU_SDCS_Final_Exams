#include <stdio.h>
#include <iostream>
#include "source.cpp"
using namespace std;

int main()
{
	cout<< getMaxScore(98, 95, 84, 89) << endl;
	cout << getMaxScore(73, 85, 90) << endl;
	cout << getMaxScore(73, 85, 90, 99) << endl;
	cout << getMaxScore(85, 85, 85, 85) << endl;
	cout << getMaxScore(85, 85, 85) << endl;
	return 0;
}