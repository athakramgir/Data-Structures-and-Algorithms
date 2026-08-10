#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << " ";
        }

        for (int j = i; j >= i; j--)
        {
            cout << 1;
        }
        for (int j = 1; j <= 2 * i - 3; j++)
        {
            cout << " ";
        }
        if (i != 1)
        {
            for (int j = i; j <= i; j++)
            {
                cout << 2;
            }
        }

        cout << endl;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }

        for (int j = i; j <= i; j++)
        {
            cout << 1;
        }
        for (int j = 2 * (n - i) - 1; j > 0; j--)
        {
            cout << " ";
        }
        if (i != n)
        {
            for (int j = i; j >= i; j--)
            {
                cout << 2;
            }
        }

        cout << endl;
    }
    return 0;
}