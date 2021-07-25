#include <iostream>
#include <string>
#include "source.cpp"
using namespace std;

int main()
{
	Dict d;
	d["pixel"] = "picture element";
	d["set"] = "math element";
	d["person"] = "animal element";
	d["football"] = "sport element";
	d["apple"] = "fruit element";
	d["water"] = "drink element";
	d["haha"] = "happy element";
	d["hehe"] = "wunai element";
	d["kao"] = "angry element";
	d["ca"] = "ca element";
	d["diu"] = "zang element";
	cout<<d["pixel"]<<endl;
	cout<<d["SET"]<<endl;
	cout<<d["FootBall"]<<endl;
	cout<<d["java"]<<endl;
	cout<<d.size()<<endl;
	cout<<d;
	d.remove("pixel");
	d.remove("Person");
	d.remove("xxxx");
	d["java"] = "computer element";
	cout<<d["pixel"]<<endl;
	cout<<d["java"]<<endl;
	cout<<d["Person"]<<endl;
	d.remove("CA");
	d.remove("kao");
	d["ai"] = "ai element";
	cout<<d["kao"]<<endl;
	cout<<d["ai"]<<endl;
	cout<<d.size()<<endl;
	cout<<d;

	return 0;
}