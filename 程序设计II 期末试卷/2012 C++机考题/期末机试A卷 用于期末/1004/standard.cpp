#include<iostream>
#include<cmath>
using namespace std;
Point::Point(int n)
{
    int i;
    dimension=n;
    data=new int[n];
    for(i=0;i<n;i++) data[i]=0;
}
Point::Point(int arr[],int n)
{
    int i;
    dimension=n;
    data=new int[n];
    for(i=0;i<n;i++) data[i]=arr[i];
}
Point Point::operator+(const Point& p)
{
    int i,*arr;
    arr=new int[max(dimension,p.dimension)];
    for(i=0;i<dimension||i<p.dimension;i++) {
        arr[i]=0;
        if(i<dimension) arr[i]+=data[i];
        if(i<p.dimension) arr[i]+=p.data[i];
    }
    return Point(arr,max(dimension,p.dimension));
}
Point Point::operator-(const Point& p)
{
    int i,*arr;
    arr=new int[max(dimension,p.dimension)];
    for(i=0;i<dimension||i<p.dimension;i++) {
        if(i<dimension) arr[i]=data[i];
        else arr[i]=0;
        if(i<p.dimension) arr[i]-=p.data[i];
    }
    return Point(arr,max(dimension,p.dimension));
}
Point& Point::operator=(const Point& p)
{
    int i;
    delete[] data;
    data=new int[p.dimension];
    dimension=p.dimension;
    for(i=0;i<p.dimension;i++) data[i]=p.data[i];
    return *this;
}
void Point::print()
{
    int i;
    cout<<"(";
    for(i=0;i<dimension-1;i++) cout<<data[i]<<",";
    cout<<data[dimension-1]<<")"<<endl;
}
