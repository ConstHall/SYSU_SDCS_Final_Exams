#include <iostream>
using namespace std;

class seriesComp
{
private:
    int n;
public:
    seriesComp(int n);
    int sum();
    int fib();
};

seriesComp::seriesComp(int number)
{
    n = number;
}

int seriesComp::sum()
{
    int i, sum;
    sum = 0;
    for(i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
int seriesComp::fib()
{
    int *f, i, sum;
    f = new int[n+1];
    f[1] = f[2] = 1;
    for(i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    sum = 0;
    for(i = 1; i <= n; i++)  {
        sum += f[i];
    }
    delete[] f;
    return sum;
}