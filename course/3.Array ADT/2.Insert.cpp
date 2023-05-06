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
    cout << endl;
}

void Insert(int index, int x, struct Array *A)
{
    if (index >= 0 && index <= A->length)
    {
        for (int i = A->length; i >= index; i--)
        {
            A->i[i] = A->i[i - 1];
        }
        A->i[index] = x;
        A->length++;
    }
}

int main()
{
    struct Array A;
    int eleIndex;
    int ele;

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

    cout << "Enter the element index you want to insert element : ";
    cin >> eleIndex;

    cout << "Enter the element value you want : ";
    cin >> ele;

    Insert(eleIndex, ele, &A);
    Display(A);

    return 0;
}