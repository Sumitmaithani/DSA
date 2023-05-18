#include <iostream>
using namespace std;

void VowelCount(char A[])
{
    int i, vcount = 0, ccount = 0;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            vcount++;
        else if ((A[i] >= 65 && A[i] <= 96) || (A[i] >= 'a' && A[i] <= 122))
            ccount++;
    }
    cout << "Vowels present is " << vcount << " and consonents are " << ccount << endl;
}

void WordCount(char A[])
{
    int i, word = 1;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
            word++;
    }
    cout << "Word are " << word << endl;
}

int main()
{
    char name[] = {'H', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', '\0'};

    VowelCount(name);
    WordCount(name);

    return 0;
}