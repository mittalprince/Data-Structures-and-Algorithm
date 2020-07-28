#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define mod 1000000009

ll n,k;
ll dp[101][MAX];
ll candies[MAX];

ll solve(ll i, ll k){
    if(i<=0 && k==0) return 1;
    if(i<=0 || k<0 || (i<=0 && k>0)) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    ll ans=0;
    for(int j=0; j<=candies[i]; j++){
        ans = (ans+solve(i-1, k-j))%mod;
    }
    // cout<<ans<<endl;
    dp[i][k]=ans%mod;
    return dp[i][k];
}

int main(){
    cin>>n>>k;
    ip(candies, n);
    memset(dp, -1, sizeof(dp));
    cout<<solve(n, k)<<endl;
    return 0;
}