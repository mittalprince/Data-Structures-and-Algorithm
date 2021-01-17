//https://leetcode.com/problems/count-sorted-vowel-strings/
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

int countVowelStrings(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n++;
    return n * (n + 1) * (n + 2) * (n + 3) / 24;
}

int countVowelStrings(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(6));
    // dp[i][j] -> total ways of constructing string on n length using j vowels
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            // 2 options
            //1. consider string with same length but with 1 less vowel, so to append a new vowel
            //2. consider string with 1 less length and append the same vowel again
            dp[i][j] = dp[i][j - 1] + (i > 1 ? dp[i - 1][j] : 1);
        }
    }
    return dp[n][5];

    /* 1D DP Approach
    vector<int> dp = {0, 1, 1, 1, 1, 1};
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= 5; ++k)
            dp[k] += dp[k - 1];
    return dp[5];
    */
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