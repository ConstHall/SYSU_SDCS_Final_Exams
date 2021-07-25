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
		int *a = new int[n];
		for( int i = 0; i < n; i++ )
			cin >> a[i];

		int count = 0;

		for( int i = 1; i < n; i++ )
		{
			int tmp = a[i];
			if( a[i] > a[i - 1] ) continue;
			else
			{
				count++;
				for( int j = i - 1; j >= 0; j-- )
				{
					if( a[j] > tmp )
					{
						a[j + 1] = a[j];
						a[j] = tmp;
					}
					else
						break;
				}
			}
		}
		cout << count * 5 << endl;
	}
	system("pause");
	return 0;
}