#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

struct Array *Union(struct Array *A, struct Array *B)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *C = new struct Array;

    while (i < A->length && j < B->length)
    {
        if (A->A[i] < B->A[j])
            C->A[k++] = A->A[i++];
        else if (A->A[i] > B->A[j])
            C->A[k++] = B->A[j++];
        else
        {
            C->A[k++] = A->A[i++];
            j++;
        }
    }

    for (; i < A->length; i++)
        C->A[k++] = A->A[i];
    for (; j < B->length; j++)
        C->A[k++] = B->A[j];

    C->length = k;
    C->size = 10;

    return C;
}

struct Array *Intersection(struct Array *A, struct Array *B)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *C = new struct Array;

    while (i < A->length && j < B->length)
    {
        if (A->A[i] < B->A[j])
            i++;
        else if (A->A[i] > B->A[j])
            j++;
        else
        {
            C->A[k++] = A->A[i++];
            j++;
        }
    }

    C->length = k;
    C->size = 10;

    return C;
}

struct Array *Difference(struct Array *A, struct Array *B)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *C = new struct Array;

    while (i < A->length && j < B->length)
    {
        if (A->A[i] < B->A[j])
            C->A[k++] = A->A[i++];
        else if (A->A[i] > B->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < A->length; i++)
        C->A[k++] = A->A[i];

    C->length = k;
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
    struct Array A = {{2, 3, 4, 10, 15}, 10, 5};
    struct Array B = {{3, 6, 7, 15, 22}, 10, 5};

    struct Array *C;
    C = Union(&A, &B);

    struct Array *D;
    D = Intersection(&A, &B);

    struct Array *E;
    E = Difference(&A, &B);

    Display(*C);
    Display(*D);
    Display(*E);

    return 0;
}

// Output :
//  Elements are : -22 -20 4 10 15 3 25 133
//  0Elements are : 0 1 3 4 5 10 15 30 35 42