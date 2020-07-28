#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
*/

int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1, amount+1);

    dp[0]=0;
    for(int i=1; i<=amount; i++){
        for(int j=0; j<coins.size(); j++){
            if(i>=coins[j]){
                dp[i] = min(dp[i-coins[j]]+1, dp[i]);
            }
        }
    }

    return dp[amount]<amount+1?dp[amount]:-1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}