#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100

ll dp[MAX]={0};

ll catlan(ll n){
    if(n<0) return 1;

    if(dp[n]>0){
        return dp[n];
    }

    ll ans=0;
    for(ll i=1; i<=n; i++){
        ans += catlan(i-1)*catlan(n-i);
    }
    return dp[n]= ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    dp[0]=dp[1]=1;

    for(ll i=0; i<=n; i++){
        cout<<catlan(i)<<endl;
    }
    
    return 0;
}