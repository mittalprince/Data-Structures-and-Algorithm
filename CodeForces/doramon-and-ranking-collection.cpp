#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, x, a[220];
    cin >> t;
    while (t--)
    {
        int freq[210] = {0};
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]] = 1;
        }
        int i, ans = 0;
        for (i = 1; i < 220; i++)
        {
            if (freq[i] != 0)
            {
                continue;
            }
            else
            {
                if (x == 0)
                {
                    break;
                }
                else
                {
                    x--;
                }
            }
        }
        ans = i - 1;
        if (x > 0)
        {
            ans + x;
        }
        cout << ans << endl;
    }
}