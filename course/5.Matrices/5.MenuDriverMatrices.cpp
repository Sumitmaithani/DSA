#include <iostream>
using namespace std;

int main()
{
    int *A, n, ch, x, i, j;

    cout << "Enter dimension : ";
    cin >> n;

    A = new int[n];

    do
    {
        cout << "Choice any number : " << endl;
        cout << "1. Create" << endl;
        cout << "2. Get" << endl;
        cout << "3. Set" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            for (i = 0; i < n; i++)
                cin >> A[i];
            break;

        case 2:
            cout << "Enter indices : ";
            cin >> i >> j;
            if (i == j)
                cout << A[i - 1] << endl;
            else
                cout << "0 " << endl;
            break;

        case 3:
            cout << "Enter row, column and element : ";
            cin >> i >> j >> x;
            if (i == j)
            {
                A[i - 1] = x;
            }
            break;

        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        cout << A[i - 1] << ' ';
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }

            break;

        default:
            break;
        }
    } while (ch < 5);

    return 0;
}