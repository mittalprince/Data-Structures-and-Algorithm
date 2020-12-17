//https://leetcode.com/problems/stone-game-ii/
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

int solve(vector<int>&piles, int m, int start, vector<vector<int> >&dp, vector<int>&suffix){
    if(start+2*m >= piles.size()){
        return suffix[start];
    }
    if(dp[start][m]!=-1)return dp[start][m];

    int ans=0;
    for(int i=1; i<=2*m; i++){
        int take = suffix[start]-suffix[start+i];
        ans = max(ans, take+ (suffix[start+i] - solve(piles, max(i,m), start+i, dp, suffix)));
    }
    return dp[start][m] = ans;
}

int stoneGameII(vector<int>& piles) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=piles.size();
    vector<vector<int> >dp(n, vector<int>(n,-1));

    vector<int>suffix(n, 0);
    suffix[n-1] = piles[n-1];

    for(int i=n-2; i>=0; i--){
        suffix[i] += suffix[i+1]+piles[i];
    }

    return solve(piles, 1, 0, dp, suffix);
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