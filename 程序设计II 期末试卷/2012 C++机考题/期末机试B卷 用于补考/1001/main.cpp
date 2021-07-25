#include <stdio.h>
#include "source.cpp"
int main() {
	//freopen("a.out", "w", stdout);

	int i;
	for (i = 1; i <= 10; ++i){
		seriesComp sc(i);
		cout << sc.sum() << endl;
		cout << sc.fib() << endl;
	}
	//system("pause");
	return 0;
}