#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000005
#define mod 1000000007

ll dp[MAX];

ll solve(int n){
    if(n<0) return 0;
    if(dp[n] != -1) return dp[n];

    dp[n] = ((n-1)%mod*(solve(n-1)+solve(n-2))%mod)%mod;
    return dp[n];
}

void bottomUp(int n){
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    dp[1]=0;

    for(int i=2; i<=n; i++){
        ll t = ((ll)dp[i-1] + dp[i-2])*(i-1);  
        dp[i] = (int) (t % mod); 
    }
    cout<<dp[n]<<endl;
}

int main(){
    int n;
    cin>>n;
    bottomUp(n);
    // memset(dp, -1, sizeof(dp));
    // dp[0]=1, dp[1]=0;
    // cout<<solve(n)<<endl;
    return 0;
}