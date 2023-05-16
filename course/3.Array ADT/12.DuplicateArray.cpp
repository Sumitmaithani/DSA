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
    cout << endl;
}

void Duplicate2(int A[], int n)
{
    int H[21] = {0};

    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    for (int i = 0; i < 20; i++)
    {
        if (H[i] > 1)
        {
            cout << i << " is repeat " << H[i] << " times." << endl;
        }
    }
}

void Duplicate3(int A[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            cout << A[i] << " is repeat " << count << " times." << endl;
        }
    }
}

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int B[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};

    Duplicate(A, 10);
    Duplicate2(A, 10);
    Duplicate3(B, 10);

    return 0;
}