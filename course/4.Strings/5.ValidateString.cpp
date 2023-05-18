#include <iostream>
using namespace std;

int validateString(char *A)
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (!(A[i] >= 65 && A[i] <= 96) && !(A[i] >= 'a' && A[i] <= 122) && !(A[i] >= 48 && A[i] <= 57))
            return 0;
    }
    return 1;
}

int main()
{
    char name[] = {'A', 'n', 'i', ' ', '1', '2', '3', '\0'};
    char *str="Ani!123";
    cout << validateString(str);

    return 0;
}