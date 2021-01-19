//https://leetcode.com/problems/largest-submatrix-with-rearrangements/
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

int largestSubmatrix(vector<vector<int>> &matrix)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> ht(m, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j])
                ht[j]++;
            else
                ht[j] = 0;
        }
        vector<int> t = ht;
        sort(t.begin(), t.end());
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, t[j] * (m - j));
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