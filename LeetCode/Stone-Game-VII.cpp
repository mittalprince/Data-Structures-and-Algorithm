//https://leetcode.com/problems/stone-game-vii/
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

// Recurrsive ++ memorization
int solve(vector<int>& stones, int i, int j, vector<vector<int> >&dp, int sum){
    if(i==j)return 0;
    if(dp[i][j])return dp[i][j];

    int opt1 = sum-stones[i]-solve(stones, i+1, j, dp, sum-stones[i]);
    int opt2 = sum-stones[j]-solve(stones, i, j-1, dp, sum-stones[j]);

    return dp[i][j] = max(opt1, opt2);
}

int stoneGameVII(vector<int>& stones) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int sum=0;
    for(int i: stones){
        sum += i;
    }
    int n=stones.size();
    vector<vector<int> >dp(n, vector<int>(n));
    return solve(stones, 0, n-1, dp, sum);
}

// 2D Approach Bottoms Up
int stoneGameVII(vector<int>& stones) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=stones.size();
    vector<int>prefix(n,0);
    for(int i=0; i<n; i++){
        prefix[i] = stones[i] + (i?prefix[i-1]:0);
    }

    vector<vector<int> >dp(n, vector<int>(n));

    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int end = i+len-1;
            int chose_front = prefix[end]-prefix[i] - dp[i+1][end];
            int chose_back = prefix[end-1] - (i?prefix[i-1]:0) - dp[i][end-1];

            dp[i][end] = max(chose_front, chose_back);
        }
    }

    return dp[0][n-1];
}

// 1D Approach Bottoms Up
int stoneGameVII(vector<int>& stones) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=stones.size();
    vector<int>prefix(n,0);
    for(int i=0; i<n; i++){
        prefix[i] = stones[i] + (i?prefix[i-1]:0);
    }

    vector<int>dp(n);

    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int end = i+len-1;
            int chose_front = prefix[end]-prefix[i] - dp[i+1];
            int chose_back = prefix[end-1] - (i?prefix[i-1]:0) - dp[i];

            dp[i] = max(chose_front, chose_back);
        }
    }

    return dp[0];
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