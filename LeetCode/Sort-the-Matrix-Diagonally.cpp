//https://leetcode.com/problems/sort-the-matrix-diagonally/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    // all elements on same diagonal have same i-j result.
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map; // min priority queue
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i - j].push(mat[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = map[i - j].top();
            map[i - j].pop();
        }
    }
    return mat;
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