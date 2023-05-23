#include <iostream>
using namespace std;

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i <= j)
        m->A[(m->n * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i)] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i <= j)
        return m.A[(m.n * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i)];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i <= j)
                cout << Get(m, i, j) << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    struct Matrix m;
    int x;

    cout << "Enter Dimension: ";
    cin >> m.n;
    m.A = new int[(m.n * (m.n + 1)) / 2];

    cout << "Enter Upper Triangle Elements:" << endl;
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = i; j <= m.n; j++)
        {
            cin >> x;
            Set(&m, i, j, x);
        }
    }

    cout << "Upper Triangle Matrix:" << endl;
    Display(m);

    delete[] m.A;

    return 0;
}
