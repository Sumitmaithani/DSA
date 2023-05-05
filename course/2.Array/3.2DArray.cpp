#include <iostream>
using namespace std;

int main()
{
    int i, j;

    //Array in stack memory
    int A[3][4] = {{1, 2, 3, 10}, {4, 5, 6, 11}, {7, 8, 9, 12}};

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    //Array in heap memory
    int *B[3];

    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    int **C;
    C = new int *[3];

    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Output :
// 1 2 3 10
// 4 5 6 11
// 7 8 9 12
// -1479971216 375 -1479999152 375
// -1479971216 375 -1479999152 375
// -1479994800 375 -1479999152 375
// -1479994800 375 -1479999152 375
// -1479994800 375 -1479999152 375
// -1479994800 375 -1479999152 375