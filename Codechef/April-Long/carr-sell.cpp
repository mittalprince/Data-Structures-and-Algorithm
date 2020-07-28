#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MOD 1000000007

bool comp(ll a, ll b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, comp);
        int i = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - i > 0)
            {
                ans += (arr[i] - i) % MOD;
            }
        }
        cout << (ans % MOD) << endl;
    }
}