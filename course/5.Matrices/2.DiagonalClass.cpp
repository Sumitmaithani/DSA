#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    };
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal()
    {
        delete[] A;
    }
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

void Diagonal::Display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << ' ';
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
    Diagonal dm(4);

    dm.Set(1, 1, 5);
    dm.Set(2, 2, 15);
    dm.Set(3, 3, 25);
    dm.Set(4, 4, 35);
    dm.Display();

    return 0;
}