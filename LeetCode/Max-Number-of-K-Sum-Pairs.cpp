//https://leetcode.com/problems/max-number-of-k-sum-pairs/
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

int maxOperations(vector<int> &nums, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> m;
    for (int &num : nums)
        m[num]++;
    int ans = 0;

    for (auto it : m)
    {
        int num = it.first, count = it.second;

        if (k - num == num)
            ans += count / 2;
        else if (m.count(k - num))
        {
            int Min = min(count, m[k - num]);
            ans += Min;
            m[num] -= Min;
            m[k - num] -= Min;
        }
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