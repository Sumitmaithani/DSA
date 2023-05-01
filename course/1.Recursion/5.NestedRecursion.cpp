#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 100)
        return n - 10;
    return fun(fun(n + 11));
}

int main()
{
    cout<<fun(1);

    return 0;
}

// Output : 91