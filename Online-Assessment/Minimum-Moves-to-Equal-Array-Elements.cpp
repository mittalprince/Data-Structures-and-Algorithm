//https://www.tutorialspoint.com/minimum-moves-to-equal-array-elements-in-cplusplus
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n)              \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define ip1(arr, n)              \
    for (int i = 1; i <= n; i++) \
        cin >> arr[i];
#define op(arr, n)              \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define fstIO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define debug(x) cout << x << "\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    ip(arr, n);

    long ans = 0;
    sort(begin(arr), end(arr));
    for (int i : arr)
    {
        ans += i - arr[0];
    }
    cout << ans << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}