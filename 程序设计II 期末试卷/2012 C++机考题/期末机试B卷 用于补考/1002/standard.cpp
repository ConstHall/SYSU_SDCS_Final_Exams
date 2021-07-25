#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void frequency(T arr[], int len)
{
	int times = 1;
	sort(arr, arr+len);

	cout<<arr[0]<<" ";
	for(int i=1; i<len; i++)
	{
		if(arr[i] != arr[i-1])
		{
			cout<<times<<endl<<arr[i]<<" ";
			times = 1;
		}
		else
			times++;
	}
	cout<<times<<endl;
}
