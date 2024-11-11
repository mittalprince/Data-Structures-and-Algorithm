// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
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

int solve(vector<vector<int>>& mat, vector<vector<int>>& dp, int row, int target, int currSum){
    if(row == mat.size()){
        return abs(target-currSum);
    }
    if(dp[row][currSum] != -1) return dp[row][currSum];
    int ans = INT_MAX;
    for(int i=0; i<mat[0].size(); i++){
        ans = min(ans, solve(mat, dp, row+1, target, currSum+mat[row][i]));
    }
    return dp[row][currSum] = ans;
}
int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>dp(n+1, vector(5001, -1));
    return solve(mat, dp, 0, target, 0);
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