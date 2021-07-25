#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int arr[1000][1000];
#include "source.cpp"

int main()
{
    int i,j,n=1,k=1,ct=0;
    for(i=0;i<1000;i++) {
        for(j=0;j<1000;j++) {
            arr[i][j]=n;
            n+=k;
            k=(k+1)%11+1;
            ct++;
        }
    }
    for(i=0;i<1000;i++) {
        if(check(arr+i,1000-i,arr[i][0])) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        if(check(arr+i,1000-i,arr[999][0])) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        if(check(arr+i,1000-i,arr[999][500-i]-i)) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        if(check(arr+i,1000-i,arr[999][999])) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        if(check(arr+i,1000-i,arr[997][i])) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    
    return 0;
}
