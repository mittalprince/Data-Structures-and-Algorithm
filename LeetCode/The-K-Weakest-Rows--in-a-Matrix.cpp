//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
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

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;
    for (int i = mat[0].size() - 1; i >= 0; i--)
    {
        for (int j = mat.size() - 1; j >= 0; j--)
        {
            if (mat[j][i] && (i == mat[0].size() - 1 || (mat[j][i + 1] == 0)))
                result.push_back(j);
        }
    }
    for (int i = mat.size() - 1; i >= 0; i--)
    {
        if (mat[i][0] == 0)
            result.push_back(i);
    }
    return vector<int>(result.rbegin(), result.rbegin() + k);
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