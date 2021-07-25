
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
#include "source.cpp"
int main()
{
    int a[1000];
    double b[1000];
    int i;
    for(i=0;i<1000;i++) {
        a[i]=(i-500)*(i-500);
        b[i]=(i-i/100)*(i-i/200)+(double)a[i]/1000000;
    }
    mySort(a,1000);
    for(i=0;i<1000;i++) cout<<a[i]<<endl;
    mySort(b,1000);
    for(i=0;i<1000;i++) cout<<b[i]<<endl;
    return 0;
}
