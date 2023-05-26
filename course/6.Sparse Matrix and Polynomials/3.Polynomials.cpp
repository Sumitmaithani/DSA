#include <iostream>
using namespace std;

struct Term
{
    int coef;
    int expo;
};

struct Polynomial
{
    int n;
    struct Term *poly;
};

int main()
{
    struct Polynomial A;
    int i;

    cout << "Enter number of terms : ";
    cin >> A.n;

    A.poly = new Term[A.n];

    cout << "Enter coefficient and exponents " << endl;
    for (i = 0; i < A.n; i++)
    {
        cout << "Enter term " << i << " cofficient and expoent value : ";
        cin >> A.poly[i].coef >> A.poly[i].expo;
    }

    for (i = 0; i < A.n; i++)
    {
        cout << A.poly[i].coef << "x"
             << "^" << A.poly[i].expo << " ";
    }

    return 0;
}