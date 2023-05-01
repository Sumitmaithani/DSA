#include <iostream>
using namespace std;

int Sum(int n)
{
    if (n == 0)
        return 0;
    return Sum(n - 1) + n;
}

int ISum(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s = s + i;
    return s;
}

int FSum(int n)
{

    return n * (n + 1) / 2;
}

int main()
{
    cout << Sum(100) << " " << ISum(100) << " " << FSum(100);

    return 0;
}

// Output : 5050 5050 5050