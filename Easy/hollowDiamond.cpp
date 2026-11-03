#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int k = n; k > i; k--)
        {
            cout << " ";
        }
        for (int l = 1; l <= i; l++)
        {
            if (l == 1)
                cout << "*";
            else
                cout << " ";
        }
        for (int m = i - 1; m > 0; m--)
        {
            if (m == 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    for (int j = 1; j < n; j++)
    {
        for (int k = 1; k <= j; k++)
            cout << " ";
        for (int l = n - 1; l >= j; l--)
        {
            if (l == (n - 1))
                cout << "*";
            else
                cout << " ";
        }
        for (int m = n - j - 1; m >= 1; m--)
        {
            if (m == 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}