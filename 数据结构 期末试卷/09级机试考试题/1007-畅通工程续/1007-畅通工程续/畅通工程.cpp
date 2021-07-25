#include <iostream>
using namespace std;

class Graph
{
public:
	Graph( int vertex )
		: v( vertex )
	{
		dis = new int[v];
		for( int i = 0; i < v; i++ )
			for( int j = 0; j < v; j++ )
				a[i][j] = -1;
	}

	void insert( int i, int j, const int &weight );
	
	void path( int s );

	void print( int end ) const;
private:
	int a[201][201];
	int v;
	int *dis;
};

void Graph::insert( int i, int j, const int &weight )
{
	a[i][j] = a[j][i] = weight;
	return ;
}

void Graph::path( int s )
{
	bool found[201];
	int w, to_insert;
	for( int i = 0; i < v; i++ )
	{
		dis[i] = a[s][i];
		found[i] = false;
	}

	found[s] = true;
	dis[s] = 0;
	for( int i = 0; i < v; i++ )
	{
		int min = 999999;
		for( w = 0; w < v; w++ )
			if( !found[w] )
				if( dis[w] < min )
				{
					to_insert = w;
					min = dis[w];
				}

		found[to_insert] = true;
		for( int i = 0; i < v; i++ )
			if( !found[i] )
				if( min + a[to_insert][i] < dis[i] )
					dis[i] = min + a[to_insert][i];
	}
	
}

void Graph::print( int end ) const
{
	if( end < v && end >= 0 )
		cout << dis[end] << endl;
	else
		cout << -1 << endl;
}
int main()
{
	int n, m;
	while( cin >> n >> m && ( n != 0 && m != 0 ) )
	{
		Graph g( n );
		int beg, end, weight;
		for( int i = 0; i < m; i++ )
		{
			cin >> beg >> end >> weight;
			g.insert( beg, end, weight );
		}
		cin >> beg >> end;
		g.path( beg );
		g.print( end );
	}
	system( "pause" );
	return 0;
}