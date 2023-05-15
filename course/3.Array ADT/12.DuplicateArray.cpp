#include <iostream>
using namespace std;

void Duplicate(int A[], int n)
{
    int lastDuplicateElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicateElement)
        {
            cout << A[i] << ' ';
            lastDuplicateElement = A[i];
        }
    }
}

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    Duplicate(A, 10);

    return 0;
}