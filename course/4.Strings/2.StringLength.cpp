#include <iostream>
using namespace std;

void StringLength(char S[])
{
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
    }
    cout << "Length of string is " << i << endl;
}

int main()
{
    char name[] = {'J', 'o', 'h', 'n', '\0'};

    StringLength(name);

    return 0;
}