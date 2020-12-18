// https: //leetcode.com/problems/stone-game-v/
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

int solve(vector<int>&A, int i, int j, vector<vector<int> >&dp, vector<int>&prefix){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];

    for(int idx=i; idx<j; idx++){
        int l = prefix[idx]-(i?prefix[i-1]:0);
        int r = prefix[j] - prefix[idx];

        if(l<r){
            dp[i][j] = max(dp[i][j], l+solve(A, i, idx, dp, prefix));
        }
        else if(l>r){
            dp[i][j] = max(dp[i][j], r+solve(A, idx+1, j, dp, prefix));
        }
        else{
            dp[i][j] = max(dp[i][j], max(l+solve(A, i, idx, dp, prefix), r+solve(A, idx+1, j, dp, prefix)));
        }
    }
    return dp[i][j];
}

int stoneGameV(vector<int>& stoneValue) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=stoneValue.size();
    vector<vector<int> >dp(n, vector<int>(n, -1));
    vector<int>prefix(stoneValue);

    for(int i=1; i<n; i++){
        prefix[i] += prefix[i-1];
    }

    return solve(stoneValue, 0, n-1, dp, prefix);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}