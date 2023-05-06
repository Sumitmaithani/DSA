#include <iostream>
using namespace std;

struct Array
{
    int *i;
    int size;
    int length;
};

void Display(struct Array A)
{
    cout << "Elements are : ";
    for (int i = 0; i < A.length; i++)
    {
        cout << A.i[i] << " ";
    }
}

int main()
{
    struct Array A;

    cout << "Enter the size of array : ";
    cin >> A.size;

    A.i = new int[A.size];

    cout << "Enter the length of array : ";
    cin >> A.length;

    cout << "Enter all elements separted by space : ";
    for (int i = 0; i < A.length; i++)
    {
        cin >> A.i[i];
    }

    Display(A);

    return 0;
}