#include <iostream>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *S)
{
    cout << "Enter dimension : ";
    cin >> S->m >> S->n;
    cout << "Enter number of non zero elements : ";
    cin >> S->num;

    S->e = new Element[S->num];

    cout << "Enter all non zero element : ";
    for (int i = 0; i < S->num; i++)
    {
        cin >> S->e[i].i >> S->e[i].j >> S->e[i].x;
    }
}

void display(struct Sparse S)
{
    int k = 0;
    for (int i = 0; i < S.m; i++)
    {
        for (int j = 0; j < S.n; j++)
        {
            if (i == S.e[k].i && j == S.e[k].j)
            {
                cout << S.e[k].x << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

struct Sparse *Add(struct Sparse *A, struct Sparse *B)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    sum = new struct Sparse;

    sum->e = new struct Element[A->num + B->num];

    while (i < A->num && j < B->num)
    {
        if (A->e[i].i < B->e[i].i)
            sum->e[k++] = A->e[i++];
        else if (A->e[i].i > B->e[i].i)
            sum->e[k++] = A->e[j++];
        else
        {
            if (A->e[i].j < B->e[i].j)
                sum->e[k++] = A->e[i++];
            else if (A->e[i].j > B->e[i].j)
                sum->e[k++] = A->e[j++];
            else
            {
                sum->e[k] = A->e[i];
                sum->e[k++].x = A->e[i++].x + B->e[j++].x;
            }
        }
    }
    for (; i < A->num; i++)
        sum->e[k++] = A->e[i];
    for (; j < B->num; j++)
        sum->e[k++] = B->e[j];
    sum->m = A->m;
    sum->n = B->n;
    sum->num = k;
    return sum;
}

int main()
{
    struct Sparse S1, S2, *S3;
    create(&S1);
    create(&S2);

    S3 = Add(&S1, &S2);

    cout << "First Matrix : " << endl;
    display(S1);
    cout << "Second Matrix : " << endl;
    display(S2);
    cout << "Third Matrix : " << endl;
    display(*S3);

    return 0;
}