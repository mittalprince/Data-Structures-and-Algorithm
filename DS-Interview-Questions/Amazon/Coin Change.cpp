// https://leetcode.com/problems/coin-change/
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

int coinChange(vector<int>& coins, int amount){
    int n = coins.size();
    int dp[amount+1];

    for(int i=0; i<=amount; i++){
        dp[i] = amount+1; // set default max value
    }
    dp[0] = 0; // base case
    for(int i=1; i<=amount; i++){
        for(int j: coins){
            if(j <= i){
                dp[i] = min(dp[i], 1+dp[i-j]);
            }
        }
    }
    if(dp[amount] != amount+1) return dp[amount];
    return -1;
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