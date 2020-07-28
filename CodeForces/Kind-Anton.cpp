#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n], brr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
        }

        map<int, bool> m;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            if (brr[i] - arr[i] > 0 && m.find(1) == m.end())
            {
                flag = false;
            }
            else if (brr[i] - arr[i] < 0 && m.find(-1) == m.end())
            {
                flag = false;
            }
            m[arr[i]] = true;
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

// link https://codeforces.com/contest/1333/problem/B