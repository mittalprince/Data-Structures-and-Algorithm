#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Say you have an array for which the i-th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit(int K, vector<int>& prices) {
    int n=prices.size();

    if(n<=1) return 0;

    if(K>=(n/2)){ // when no of transaction > possible transaction
        // then we add positive slope (that is at each step what will be positive proft i can gain)
        int ans=0;
        for(int i=1; i<n; i++){
            if(prices[i]>prices[i-1])
                ans += prices[i]-prices[i-1];
        }
        return ans;
    }

    int dp[1001][1001]={0};
    // dp[i][j] -> what will be max profit if I have total j stocks and I can make i trsactions
    // base case -> 1. if k=0, i can't make any trasaction so profit will be 0
    // 2. if i have only 0 stock(i.e j  is 0) then also profit 0 as i can't sell or purchase

    for(int k=1; k<=K; k++){
        for(int i=1; i<n; i++){
            int ans=0;
            for(int j=0; j<i; j++){
                if(prices[i]>prices[j]){
                    // if I make trasaction at i,j(means purchase at j and sell at i) then we will add result of k-1 trasaction with j stocks
                    ans = max(ans, prices[i]-prices[j]+dp[k-1][j]);
                }
            }
            dp[k][i] = max(ans, dp[k][i-1]); // also check for same trsaction but with one less stock
        }
    }
    return dp[K][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}