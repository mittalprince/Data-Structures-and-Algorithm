#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll n, ll k)
{
    vector<int> arr;
    while (n % 2 == 0)
    {
        arr.push_back(2);
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            n = n / i;
            arr.push_back(i);
        }
    }
    if (n > 2)
        arr.push_back(n);
    if (arr.size() < k)
        return false;
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << check(n, k) << endl;
    }
}
