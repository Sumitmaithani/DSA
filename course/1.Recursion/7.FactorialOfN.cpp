#include <iostream>
using namespace std;

int Factorial(int n)
{
    if (n == 0)
        return 1;
    return Factorial(n - 1) * n;
}

int IFactorial(int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s = s * i;
    return s;
}

int main()
{
    cout << Factorial(5) << " " << IFactorial(5);

    return 0;
}

// Output : 120 120