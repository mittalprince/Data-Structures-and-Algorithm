//https://leetcode.com/problems/calculate-money-in-leetcode-bank/
#include <iostream>
#include <vector>
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

int totalMoney(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 1;
    int arr[1005] = {0};
    arr[0] = 1;
    for (int i = 1; i < n; ans += arr[i++])
    {
        if (i % 7)
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 7] + 1;
    }
    return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);

    return 0;
}