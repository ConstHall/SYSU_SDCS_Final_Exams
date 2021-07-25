#include <iostream>
#include <list>
using namespace std;
class HashTable
{
public:
	HashTable();
	int hash( int key );
	void insert( int key );
	void print() const;
private:
	list<int> *hashlist;
};

HashTable::HashTable()
{
	hashlist = new list<int>[13];
}

int HashTable::hash( int key )
{
	return key % 13;
}

void HashTable::insert( int key )
{
	int index = hash( key );
	hashlist[index].push_back( key );
}

void HashTable::print() const
{
	for( int i = 0; i < 13; i++ )
	{
		list<int>::iterator iter = hashlist[i].begin();
		cout << i << "#" << *iter;
		iter++;
		while( iter != hashlist[i].end() )
		{
			cout << " " << *iter;
			iter++;
		}
		cout << endl;
	}
}

int main()
{
	int n;
	HashTable h;
	while( cin >> n && n )
	{
		for( int i = 0; i <= n; i++ )
		{
			int x;
			cin >> x;
			if( !x ) break;
			h.insert( x );
		}
		h.print();
	}
	system("pause");
	return 0;
}