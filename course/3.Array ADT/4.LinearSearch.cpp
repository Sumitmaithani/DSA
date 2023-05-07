#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int search(int A[], int length, int search)
{
    for (int i = 0; i < length; i++)
    {
        if (search == A[i])
        {
            swap(&A[0], &A[i]);
            i--;
            return i;
        }
    }
    return -1;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << search(A, 10, 5) << endl;

    for (int i = 0; i < 10; i++)
        cout << A[i] << ' ';

    return 0;
}