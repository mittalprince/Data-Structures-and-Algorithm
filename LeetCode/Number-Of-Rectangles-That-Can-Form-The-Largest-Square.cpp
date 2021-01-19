//https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
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

int countGoodRectangles(vector<vector<int>> &rectangles)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 0;
    int n = rectangles.size();
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, min(rectangles[i][0], rectangles[i][1]));
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += mx == min(rectangles[i][0], rectangles[i][1]);
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