#include <iostream>
using namespace std;

int search(int A[], int length, int search)
{
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h)
    {
        mid = l + h / 2;
        if (search == A[mid])
            return mid;
        else if (search < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << search(A, 10, 5) << endl;

    for (int i = 0; i < 10; i++)
        cout << A[i] << ' ';

    return 0;
}