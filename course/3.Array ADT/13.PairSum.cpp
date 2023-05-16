#include <iostream>
using namespace std;

int PairSum(int A[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " + " << A[j] << " = " << k << endl;
            }
        }
    }
}

int main()
{
    int A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    PairSum(A, 10, 10);

    return 0;
}