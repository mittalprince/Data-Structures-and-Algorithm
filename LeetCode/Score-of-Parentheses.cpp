//https://leetcode.com/problems/score-of-parentheses/
#include <iostream>
#include <vector>
#include <stack>
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

int scoreOfParentheses(string s)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0, open = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            open++;
        else
        {
            open--;
            if (s[i - 1] == '(')
            {
                cout << (1 << open) << " ";
                ans += (1 << open);
            }
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