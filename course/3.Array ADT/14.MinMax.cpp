#include <iostream>
using namespace std;

void MinMax(int A[], int n)
{
    int i;
    int Min = A[0];
    int Max = A[0];

    for (i = 0; i < n; i++)
    {
        if (A[i] < Min)
        {
            Min = A[i];
        }
        else if (A[i] > Max)
        {
            Max = A[i];
        }
        i++;
    }
    cout << "Min : " << Min << " Max : " << Max << endl;
}

int main()
{
    int A[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    MinMax(A, 10);

    return 0;
}