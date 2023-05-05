#include <iostream>
using namespace std;

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p;
    p = new int[10];

    p[0] = 6;
    p[1] = 7;
    p[2] = 8;
    p[3] = 9;
    p[4] = 10;

    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";

    for (int i = 0; i < 5; i++)
        cout << p[i] << " ";

    return 0;
}

// Output : 1 2 3 4 5 6 7 8 9 10