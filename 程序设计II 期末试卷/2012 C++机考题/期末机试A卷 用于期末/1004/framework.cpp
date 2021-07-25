#include<iostream>
#include<cmath>
class Point
{
private:
    int *data;
    int dimension;
public:
    Point(int);
    Point(int[],int);
    Point operator+(const Point&);
    Point operator-(const Point&);
    Point& operator=(const Point&);
    void print();
};

using namespace std;

Point::Point(int d) {
	data = new int[d];
	for (int i = 0; i < d; i++) 
		data[i] = 0;
}
Point::Point(int t[], int d) {
	dimension = d;
	data = new int[d];
	for (int i = 0; i < d; i++) 
		data[i] = t[i];
}
Point Point::operator+(const Point& p) {
	int i,*arr;
    arr=new int[max(dimension,p.dimension)];
    for(i=0;i<dimension||i<p.dimension;i++) {
        arr[i]=0;
        if(i<dimension) arr[i]+=data[i];
        if(i<p.dimension) arr[i]+=p.data[i];
    }
    return Point(arr,max(dimension,p.dimension));
}
Point Point::operator-(const Point& p) {
	int i,*arr;
    arr=new int[max(dimension,p.dimension)];
    for(i=0;i<dimension||i<p.dimension;i++) {
        if(i<dimension) arr[i]=data[i];
        else arr[i]=0;
        if(i<p.dimension) arr[i]-=p.data[i];
    }
    return Point(arr,max(dimension,p.dimension));
}
Point& Point::operator=(const Point& p) {
	int i;
    delete[] data;
    data=new int[p.dimension];
    dimension=p.dimension;
    for(i=0;i<p.dimension;i++) data[i]=p.data[i];
    return *this;
}
void Point::print() {
	cout << "(";
	for (int i = 0; i < (dimension-1); i++) {
		cout << data[i] << ",";
	}
	cout << data[dimension-1] << ")" << endl;
}

using namespace std;


int main()
{
    int arr1[100],arr2[200],i;
    for(i=0;i<100;i++) arr1[i]=i;
    for(i=0;i<200;i++) arr2[i]=2*i-i/2+2;
    Point a(arr1,100);
    Point b(arr2,200);
    Point c(10);
    Point d(150);
    (a+b).print();
    (b+a).print();
    (a-b).print();
    (b-a).print();
    c.print();
    c=a;
    c.print();
    d=a;
    d.print();
    return 0;
}
