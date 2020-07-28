#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        int prev = -1;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 1)
            {
                if (prev != -1)
                {
                    if (i - prev < 6)
                    {
                        flag = false;
                        break;
                    }
                }
                prev = i;
            }
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}