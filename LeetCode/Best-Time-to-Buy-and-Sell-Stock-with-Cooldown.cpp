// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
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

int maxProfit(vector<int>& prices) {
    int n=prices.size();

    if(n<=1)return 0;
    if(n == 2){
        return max(0, prices[1]-prices[0]);
    }

    /*
        We already have a stock on day i : stored in dp[i][1] (we will select max of the 2)
        a. We already have it from previous day: dp[i-1][1]
        b. We bought it today: dp[i-2][0]-prices[i]
        We do dp[i-2] because, one day is left for cooldown
        We have no stock on day i : stored in dp[i][0] (we will select max of the 2)
        a. We sell it today : dp[i-1][1] + prices[i]
        b. We did not have a stock earlier too : dp[i-1][0]
    */

    int dp[n][2];
    dp[0][0]=0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(dp[0][0], dp[0][1]+prices[1]);
    dp[1][1] = max(dp[0][1], dp[0][0]-prices[1]);

    for(int i=2; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
    }

    return dp[n-1][0];
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