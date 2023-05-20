#include <iostream>
using namespace std;

void Duplicate(char A[])
{
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
        for (j = i + 1; A[j] != '\0'; j++)
        {
            if (A[i] == A[j])
            {
                cout << A[i] << " ";
            }
        }
    }
}

int main()
{
    char A[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};
    char B[] = {'m', 'a', 'd', 'a', 'm', '\0'};

    Duplicate(B);

    return 0;
}