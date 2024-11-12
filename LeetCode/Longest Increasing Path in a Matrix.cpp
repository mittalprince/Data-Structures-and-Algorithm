// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int dp[201][201];
int dfs(vector<vector<int>> &matrix, int i, int j, int pre) {
    if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || pre >= matrix[i][j])
        return 0;
    if (dp[i][j]) return dp[i][j];
    int p = matrix[i][j];
    matrix[i][j] = -1;
    int l = dfs(matrix, i, j - 1, p);
    int r = dfs(matrix, i, j + 1, p);
    int u = dfs(matrix, i - 1, j, p);
    int d = dfs(matrix, i + 1, j, p);
    matrix[i][j] = p;
    return dp[i][j] = max({l, r, u, d}) + 1;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxVal = 0;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            maxVal = max(maxVal, dfs(matrix, i, j, -1));
    return maxVal;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}