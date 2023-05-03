#include <iostream>
using namespace std;

int fibonacci(int x)
{
    int a = 0;
    int b = 1;

    if (x <= 1)
        return x;
    return fibonacci(x - 2) + fibonacci(x - 1);
}

int Ifibonacci(int x)
{
    int a = 0;
    int b = 1;
    int s = 0;

    if (x <= 1)
        return x;
    for (int i = 2; i <= x; i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

int F[10];

int Mfibonacci(int x)
{
    int a = 0;
    int b = 1;
    int s = 0;

    if (x <= 1)
        return x;
    if (F[x - 2] == -1)
        F[x - 2] = Mfibonacci(x - 2);
    if (F[x - 1] == -1)
        F[x - 1] = Mfibonacci(x - 1);
    return Mfibonacci(x - 2) + Mfibonacci(x - 1);
}

int main()
{
    cout << fibonacci(10) << ' ' << Ifibonacci(10) << ' ' << Mfibonacci(10);

    return 0;
}

// Output : 55 55 55