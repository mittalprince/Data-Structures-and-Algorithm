#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define MAX 100005

ll a,b,k;
ll dp[MAX], prefix[MAX];

ll solve(ll len, ll k){
    if(len == 0) return 1;
    if(dp[len] != -1) return dp[len];

    ll opt1 = solve(len-1, k);
    if(len>=k) opt1= (opt1+solve(len-k, k))%mod;

    dp[len]=opt1;
    return dp[len];
}

void preCompute(){
    memset(dp,-1,sizeof(dp));
	prefix[0] = 0;

    for(int i=1; i<=100000; i++){
        prefix[i] = prefix[i-1]+solve(i, k);
        prefix[i] %= mod;
    }
}

int main(){
    int t;
    cin>>t>>k;
    preCompute();
    while(t--){
        cin>>a>>b;
        cout<<(prefix[b]-prefix[a-1]+mod)%mod<<endl;
    }
    
    return 0;
}