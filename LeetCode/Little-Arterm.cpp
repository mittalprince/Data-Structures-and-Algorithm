#include <iostream>
using namespace std;
#define MAX 100

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int b = 0, w = 0;
        char arr[MAX][MAX];
        for (int i = 0; i < n; i++)
        {
            char s = (i & 1) ? 'W' : 'B';
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = s;
                (s == 'B') ? b++ : w++;
                if (s == 'W')
                    s = 'B';
                else
                    s = 'W';
            }
        }
        if (b == w)
        {
            if (arr[n - 1][m - 1] != 'B')
                arr[n - 1][m - 1] = 'B';
            else
                arr[n - 2][m - 1] = 'B';
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}

// https://codeforces.com/contest/1333/problem/A