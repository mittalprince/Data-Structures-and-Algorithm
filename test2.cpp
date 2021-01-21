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

    string s, t;
    cin >> s >> t;

    ll e1 = 0, e2 = 0, o1 = 0, o2 = 0;
    vector<int> one, two;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '1')
        {
            e1++;
            one.push_back(i);
        }
        else
            o1++;
    }
    for (int i = 0; i < n; i++)
    {

        if (t[i] == '1')
        {
            e2++;
            two.push_back(i);
        }
        else
            o2++;
    }

    if (e1 != e2)
    {
        cout << "No\n";
        return;
    }

    bool flag = 0;
    for (int i = 0; i < one.size(); i++)
    {
        if (one[i] > two[i])
        {
            cout << "No\n";
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "Yes\n";
    }
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