#include <iostream>
using namespace std;

void Display(int A[], int length)
{
    cout << "Elements are : ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void Reverse(int A[], int length)
{
    int B[length - 1];
    int i, j;

    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }

    for (i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
}

void Reverse2(int A[], int length)
{
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

int main()
{
    int A[] = {8, 2, 9, 4, 15, 6, 7, 0, 9, 0};

    Reverse(A, 10);
    Display(A, 10);
    Reverse2(A, 10);
    Display(A, 10);

    return 0;
}

// Output :
// Elements are : 0 9 0 7 6 15 4 9 2 8
// Elements are : 8 2 9 4 15 6 7 0 9 0