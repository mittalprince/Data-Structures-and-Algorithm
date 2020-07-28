#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(false);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[3] = {0};
        cin >> arr[0] >> arr[1];
        arr[2] = arr[0] ^ arr[1];
        ll div = n / 3;
        int rem = n % 3;

        ll prefix = 0;
        if (div & 1)
        {
            prefix = arr[0] ^ arr[1] ^ arr[2];
        }
        while (rem > 0)
        {
            prefix ^= arr[rem - 1];
            rem--;
        }

        int q;
        cin >> q;
        while (q--)
        {
            ll x;
            cin >> x;
            cout << (prefix ^ (arr[(x - 1) % 3])) << endl;
        }
    }
}