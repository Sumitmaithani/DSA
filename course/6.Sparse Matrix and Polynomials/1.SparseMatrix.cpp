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

int main()
{
    struct Sparse S;
    create(&S);
    display(S);

    return 0;
}