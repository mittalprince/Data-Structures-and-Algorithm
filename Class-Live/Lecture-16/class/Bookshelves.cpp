#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,k;
ll arr[55], prefix[55];
ll dp[55][55];

bool isPossible(ll i, ll k, ll mask){
    if(i==n+1){
        return k==0;
    }
    if(k==0) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    for(int j=i; j<=n; j++){
        if(((prefix[j]-prefix[i-1])&mask) == mask){// check mask is subset of diff or not
            if(isPossible(j+1, k-1, mask)){
                return dp[i][k]=1;
            }
        }
    }

    return dp[i][k]=0;
}

int main(){
    cin>>n>>k;
    ip(arr, n);

    for(int i=1; i<=n; i++){
        prefix[i]=prefix[i-1]+arr[i-1];
    }

    ll ans=0;
    // try to fix msb first, as it will maximize th beauty
    for(int i=60; i>=0; i--){
        memset(dp, -1, sizeof(dp));
        if(isPossible(1, k, ans|(1ll<<i))){
            ans |= (1ll<<i);
        }
    }
    cout<<ans<<endl;
    return 0;
}