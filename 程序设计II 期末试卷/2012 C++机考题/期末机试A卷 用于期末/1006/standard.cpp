#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

class Dict
{
public:
	string& operator[](string);
	void remove(string);
	int size();
	friend ostream& operator<<(ostream&, const Dict&);
private:
	map<string, string> m;
};

string& Dict::operator [](string s)
{
	for(int i=0; i<s.length(); i++)
		s[i] = tolower(s[i]);
	m.insert(pair<string, string>(s, "*** not in dictionary"));
	map<string, string>::iterator it= m.find(s);
	return m[s];
}

void Dict::remove(string s)
{
	for(int i=0; i<s.length(); i++)
		s[i] = tolower(s[i]);
	map<string, string>::iterator it = m.find(s);
	m.erase(it);
}

int Dict::size()
{
	map<string, string>::const_iterator it = m.begin();
	int count = 0;
	while(it != m.end())
	{
		if(it->second != "*** not in dictionary")
			count++;
		it++;
	}
	return count;
}

ostream& operator<<(ostream& out,  const Dict& d)
{
	map<string, string>::const_iterator it = d.m.begin();
	while(it != d.m.end())
	{
		if(it->second != "*** not in dictionary")
			out<<it->first<<"->"<<it->second<<endl;
		it++;
	}
	return out;
}