//https://leetcode.com/problems/stone-game/
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

// Recussive with memorization
int solve(vector<int>&piles, int start, int end, vector<vector<int> >&dp){
    if(start==end){
        return piles[start];
    }
    if(dp[start][end]!=-1)return dp[start][end];

    int ans = piles[start]-solve(piles, start+1, end, dp);
    ans = max(ans, piles[end]-solve(piles, start, end-1, dp));

    return dp[start][end]=ans;
}

bool stoneGame(vector<int>& piles) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=piles.size();
    vector<vector<int> >dp(n, vector<int>(n, -1));

    return solve(piles, 0, n-1, dp);
}

// 2D Approach
bool stoneGame(vector<int>& piles) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=piles.size();
    vector<vector<int> >dp(n, vector<int>(n, 0)); 
    // dp[i][j] -> whose one has maximum stone in the range [i] to [j]
    // if +ve means alex has max
    // if -ve means lee has max

    for(int i=0; i<n; i++){
        dp[i][i] = piles[i];
    }

    for(int len=1; len<n; len++){
        for(int i=0; i<n-len; i++){
            int j = i+len;
            dp[i][j] = max(piles[i] - dp[i+1][j], piles[j]-dp[i][j-1]);
        }
    }
    return dp[0][n-1]>0;
}

// 1D Approach
bool stoneGame(vector<int>& piles) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=piles.size();
    vector<int>dp(piles);
    /*
    since we require only prev window and curr window (len -> window size, i -> start idx)
    so we use only 1D as prev state will be stored in dp[i] and
    curr window ans will be calculated now

    2 option
    1. pick from start -> piles[i] - dp[i+1]
       means start pick kia and ask what will be max stone if we have one less elemt(i+1)
       i.e simple window size dec as one elemt less, but from where window start i+1

    2. pick from end -> piles[end] - dp[i]
       means end pick kia and ask what will be max stone if we have one less elemt(as end pick)
       i.e simple window size dec as one elemt less, but from where window start i and dp[i]
       store prev window (len-1) result

     */

    for(int len=1; len<n; len++){
        for(int i=0; i<n-len; i++){
            int end = i+len;
            dp[i] = max(piles[i]-dp[i+1], piles[end] - dp[i]);
        }
    }
    return dp[0]>0;
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