#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll n;
ll dp[25][(1<<21)];
ll arr[25][25];

ll solve(ll i, ll womens){
    if(i == n){
        return womens == 0;
    }
    if(dp[i][womens] != -1) return dp[i][womens];

    ll ans=0;
    for(int w=0; w<n; w++){
        bool available = womens&(1<<w);
        if(available && arr[i][w]){
            ans = (ans+solve(i+1, womens&(~(1<<w))))%mod;
        }
    }
    return dp[i][womens]=(ans%mod);
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, (1<<n)-1)<<endl;
    
    return 0;
}