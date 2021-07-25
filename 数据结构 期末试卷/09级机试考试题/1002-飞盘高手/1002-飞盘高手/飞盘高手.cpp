#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while( n-- )
	{
		int x;
		queue<int> q;
		cin >> x;
		for( int i = 1; i <= x; i++ )
			q.push( i );
		while( !q.empty() )
		{
			cout << q.front();
			q.pop();
			if( q.empty() ) break;
			cout << " ";
			q.push( q.front() );
			q.pop();
		}
	}
	system("pause");
	return 0;
}