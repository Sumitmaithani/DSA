#include <iostream>
using namespace std;

void Lowercase(char A[])
{
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
            A[i] += 32;
    }
    cout << A << endl;
}

void Uppercase(char A[])
{
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 'a' && A[i] <= 122)
            A[i] -= 32;
    }
    cout << A << endl;
}

int main()
{
    char name[] = {'J', 'o', 'H', 'n', '\0'};

    Lowercase(name);
    Uppercase(name);

    return 0;
}