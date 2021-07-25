#include <iostream>
#include<map>
#include<string>
using namespace std;
class student
{
private:
    map<int,string> stu;
public:
    void reg(int,string);
    bool graduate(int,string);
    string findName(int);
};
#include "source.cpp"
string intToString(int id)
{
    string s;
    if(id==0) return "a";
    while(id) {
        string temp="z";
        temp[0]=id%10+'a';
        id/=10;
        s+=temp;
    }
    return s;
}
int main()
{
    int i;
    student stu;
    for(i=0;i<1000;i++) stu.reg(i,intToString(i));
    for(i=0;i<15;i++) {
        if(stu.graduate(i,intToString(i+1))) cout<<"graduate"<<endl;
        else cout<<"not graduate"<<endl;
    }
    for(i=15;i<25;i++) {
        if(stu.graduate(i,intToString(i))) cout<<"graduate"<<endl;
        else cout<<"not graduate"<<endl;
    }
    for(i=-10;i<1100;i++) {
        string name=stu.findName(i);
        if(name!="") cout<<name<<endl;
        else cout<<"null"<<endl;
    }
    return 0;
}
