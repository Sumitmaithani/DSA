#include <iostream>
using namespace std;

int main()
{
    int *p, *q;
    int i;

    p = new int[5];

    p[0] = 6;
    p[1] = 7;
    p[2] = 8;
    p[3] = 9;
    p[4] = 10;

    q = new int[10];

    for (int i = 0; i < 5; i++)
        q[i] = p[i];

    free(p);
    p = q;
    q = NULL;

    for (int i = 0; i < 5; i++)
        cout << p[i] << " ";

    return 0;
}

// Output : 6 7 8 9 10