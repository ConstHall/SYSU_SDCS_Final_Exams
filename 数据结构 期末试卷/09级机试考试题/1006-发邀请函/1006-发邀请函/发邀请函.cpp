#include <iostream>
using namespace std;

int binSearch( int a[], int low, int high, const int &target )
{
	while( low < high )
	{
		int mid = ( low + high ) / 2;
		if( a[mid] < target )
			low = mid + 1;
		else
			high = mid;
	}
	if( low > high )
		return -1;
	else
	{
		if( target == a[low] )
			return low;
		else
			return -1;
	}
}

int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		int m, n;
		cin >> m >> n;
		int *visit = new int[m];
		int *home = new int[n];

		for( int i = 0; i < m; i++ )
			cin >> visit[i];
		
		for( int i = 0; i < n; i++ )//home[1]¾ÍÊÇLily¼Ò
			cin >> home[i];

		for( int i = 0; i < m; i++ )
		{
			int index = binSearch( home, 0, n - 1, visit[i] );
			if( index >= 0 )
				cout << index * 50 << endl;
		}
	}
	system("pause");
	return 0;
}