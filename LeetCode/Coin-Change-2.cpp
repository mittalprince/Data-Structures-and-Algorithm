//https://leetcode.com/problems/coin-change-2/
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

int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));

    dp[0][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=amount; j++){
            if(j==0){
                dp[i][j]=1;
            }
            else if(j>=coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][amount];
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