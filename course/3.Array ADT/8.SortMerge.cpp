#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void InsertSort(struct Array *A, int x)
{
    int i = A->length - 1;

    if (A->length == A->size)
        return;

    while (i >= 0 && A->A[i] > x)
    {
        A->A[i + 1] = A->A[i];
        i--;
    }
    A->A[i + 1] = x;
    A->length++;
}

int IsSorted(struct Array A)
{
    for (int i = 0; i < A.length - 1; i++)
    {
        if (A.A[i] > A.A[i + 1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *A)
{
    int i;
    int j;

    i = 0;
    j = A->length - 1;

    while (i < j)
    {
        while (A->A[i] < 0)
            i++;
        while (A->A[j] >= 0)
            j--;
        if (i < j)
            swap(&A->A[i], &A->A[j]);
    }
}

struct Array *Merge(struct Array *A, struct Array *B)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *C = new struct Array;

    while (i < A->length && j < B->length)
    {
        if (A->A[i] < B->A[j])
            C->A[k++] = A->A[i++];
        else
            C->A[k++] = B->A[j++];
    }

    for (; i < A->length; i++)
        C->A[k++] = A->A[i];
    for (; j < B->length; j++)
        C->A[k++] = B->A[j];

    C->length = A->length + B->length;
    C->size = 10;

    return C;
}

void Display(struct Array A)
{
    cout << "Elements are : ";
    for (int i = 0; i < A.length; i++)
    {
        cout << A.A[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Array A = {{-22, 3, 4, 10, 15, -20, 25, -30, 35}, 10, 7};
    InsertSort(&A, 133);
    Rearrange(&A);
    Display(A);
    cout << IsSorted(A);

    struct Array B = {{1, 3, 4, 10, 15}, 10, 5};
    struct Array C = {{0, 5, 30, 35, 42}, 10, 5};

    struct Array *D;
    D = Merge(&B, &C);

    Display(*D);

    return 0;
}

// Output :
//  Elements are : -22 -20 4 10 15 3 25 133
//  0Elements are : 0 1 3 4 5 10 15 30 35 42