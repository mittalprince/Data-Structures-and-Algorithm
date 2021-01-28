//https://leetcode.com/problems/wildcard-matching/
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

bool isMatch(string s, string p)
{
    int n = p.size();
    int m = s.size();

    bool dp[2001][2001] = {0};
    dp[0][0] = 1; // empty string match with empty pattern

    for (int i = 1; i <= n; i++)
    {
        if (p[i - 1] == '*')
            dp[i][0] = dp[i - 1][0]; // so when string is epmpty, but pattern not
        // when there is * in pat then we check whther we can make equal them or not
    }

    for (int i = 1; i <= n; i++)
    {
        // for ith char in pattern we fill the entire row
        int j = 1;

        if (p[i - 1] == '*')
        {
            while (j <= m)
            {
                if (dp[i - 1][j - 1] || dp[i - 1][j])
                {
                    while (j <= m)
                        dp[i][j++] = 1;
                    // point 4, when pattern come and string upto (i-1,j-1)|(i-1,j) match them fill entire row with 1, as now * can match everthing
                }
                j++;
            }
        }
        else if (p[i - 1] == '?')
        {
            while (j <= m)
            {
                dp[i][j] = dp[i - 1][j - 1];
                j++;
            }
        }
        else
        {
            while (j <= m)
            {
                if (p[i - 1] == s[j - 1])
                {
                    dp[i][j] = (true && dp[i - 1][j - 1]);
                }
                j++;
            }
        }
    }

    return dp[n][m];
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