#include <iostream>
#include <string>
#include "source.cpp"
using namespace std;

int main()
{
	int a[10] = {2, 2, 3, 7, 8, 9, 3, 7, 6, 1};
	frequency(a, 10);
	double b[8] = {5.5, 4.4, 3.1, 7.1, 4.4, 2.2, 5.5, 8.3};
	frequency(b, 8);
	string c[6] = {"am", "is" ,"are", "are", "is", "am"};
	frequency(c, 6);
	int d[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	frequency(d, 20);
	double e[10] = {0.1 , 0.5, 1.1, 2.1, 3.5, 4.4, 2.2, 4.4, 1.1, 2.1};
	frequency(e, 10);
	string f[10] = {"ha", "hi", "hei", "he", "heng", "he", "hu", "hi", "hi", "ha"};
	frequency(f, 10);
	int g[6] = {1, 1, 1, 1, 1, 1};
	frequency(g, 6);
	int h[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	frequency(h, 40);
	return 0;
}