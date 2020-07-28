#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define inf 100000000000

ll n, capacity;
ll price[105], wt[105];
ll dp[105][MAX];

ll solve(ll max_profit){

    for(int i=0; i<=n; i++){
        for(int j=0; j<=max_profit; j++){
            if(i==0){
                if(j==0) dp[i][j]=0;
                else dp[i][j]=inf;
            }
            else if(j>=price[i-1]){
                dp[i][j] = min(dp[i-1][j], wt[i-1]+dp[i-1][j-price[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    ll ans=0;
    for(int i=0; i<=max_profit; i++){
        if(dp[n][i]<=capacity) ans=i;
    }
    return ans;
}

int main(){
    ll max_profit=0;
    cin>>n>>capacity;
    for(int i=0; i<n; i++){
        cin>>wt[i]>>price[i];
        max_profit += price[i];
    }
    cout<<solve(max_profit)<<endl;
    return 0;
}