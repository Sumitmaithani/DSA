#include <iostream>
using namespace std;

void MissingElement(int A[], int n)
{
    int diff = A[0] - 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << diff + i << " ";
                diff++;
            }
        }
    }
}

void MissingElement2(int A[], int n)
{
    int H[n] = {0};

    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (H[i] == 0)
        {
            cout << i << ' ';
        }
    }
}

int main()
{
    int A[11] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int B[10] = {3, 7, 4, 9, 12, 16, 1, 11, 2, 10};
    MissingElement(A, 11);
    MissingElement2(B, 10);

    return 0;
}