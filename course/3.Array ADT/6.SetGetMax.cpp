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

void Get(int A[], int index, int length)
{
    if (index >= 0 && index < length)
    {
        cout << "Get elements is : " << A[index] << endl;
    }
}
void Set(int A[], int index, int element, int length)
{
    if (index >= 0 && index < length)
    {
        A[index] = element;
    }
}

void Max(int A[], int length)
{
    int max = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    cout << "Max element is " << max << endl;
}

void Min(int A[], int length)
{
    int min = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << "Min element is " << min << endl;
}

void Sum(int A[], int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    cout << "Sum of all elements is " << sum << endl;
}

void Avg(int A[], int length)
{
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    avg = sum / length;
    cout << "Avg of all elements is " << avg << endl;
}

int main()
{
    int A[] = {8, 2, 9, 4, 15, 6, 7, 0, 9, 0};

    Display(A, 10);
    Get(A, 6, 10);
    Set(A, 6, 90, 10);
    Display(A, 10);
    Max(A, 10);
    Min(A, 10);
    Sum(A, 10);
    Avg(A, 10);

    return 0;
}

// Output :
// Elements are : 8 2 9 4 15 6 7 0 9 0
// Get elements is : 7
// Elements are : 8 2 9 4 15 6 90 0 9 0
// Max element is 90
// Min element is 0
// Sum of all elements is 143
// Avg of all elements is 14