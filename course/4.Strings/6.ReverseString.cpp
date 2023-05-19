#include <iostream>
using namespace std;

void Reverse(char A[])
{
    int i, j;
    char t;
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout << A << endl;
}

int main()
{
    char A[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};
    Reverse(A);

    return 0;
}