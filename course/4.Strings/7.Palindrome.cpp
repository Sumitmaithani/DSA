#include <iostream>
#include <cstring>
using namespace std;

void Palindrome(char A[], int x)
{
    int i, j;
    char t;
    char B[x];

    for (j = 0; A[j] != '\0'; j++)
    {
        B[j] = A[j];
    }

    B[j] = '\0';
    j = j - 1;

    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }

    if (strcmp(B, A) == 0)
        cout << B << " is a palindrome string " << A << endl;
    else
        cout << B << " is a not palindrome string " << A << endl;
}

int main()
{
    char A[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};
    char B[] = {'m', 'a', 'd', 'a', 'm', '\0'};

    Palindrome(A, 7);
    Palindrome(B, 6);

    return 0;
}