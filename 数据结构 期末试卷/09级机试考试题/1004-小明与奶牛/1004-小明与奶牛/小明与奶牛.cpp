#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		int n;
		cin >> n;
		int a[5] = {-1, -1, -1, -1, -1};
		for( int i = 0; i < n; i++ )
		{
			int m, n;
			cin >> m >> n;
			if( n > a[m] )
					a[m] = n;
		}
		for( int i = 1; i <= 3; i++ )
		{
			if( a[i] < 0 ) continue;
			else
				cout << i << " " << a[i] << endl;
		}
	}
	system("pause");
	return 0;
}