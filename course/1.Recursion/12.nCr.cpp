#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

int nCr(int n, int r)
{
    int num = factorial(n);
    int den = factorial(r) * factorial(n - r);
    return num / den;
}

int NCR(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main()
{
    cout << nCr(5, 1) << " " << NCR(4, 2);

    return 0;
}

// Output : 5 6