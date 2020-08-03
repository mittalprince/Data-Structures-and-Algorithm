// https://www.hackerearth.com/problem/algorithm/maximum-bitwise-pair-bb846052/description/?layout=old
#include<iostream>
#include<vector>
#include<cstring>
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

ll n,q,x,a;
ll dp[(1<<17)];
ll *arr;

ll findIndex(ll mask){
    if(dp[mask] != -1)return dp[mask];

    ll ans = (mask<=n)?arr[mask]:-2;

    for(int i=0; i<17; i++){
        if(mask & (1<<i)){ // check if ith pos is available or not if 1 yes otherwise no
            ans = max(ans, findIndex(mask ^ (1<<i))); // make this ith pos as 0 means we considered this
        }
    }

    return dp[mask]=ans;
}

void solve(){
    cin>>n;
    arr = new ll[n+1];

    ip1(arr, n);
    arr[0]=-2;

    memset(dp, -1, sizeof(dp));

    cin>>q;
    for(int i=0; i<q; i++){
        cin>>x;

        a = ((1<<17)-1)^x;
        ll ans = findIndex(a);
        if(ans == -2){
            cout<<"-1\n";
        }
        else{
            cout<<arr[x]+ans<<endl;
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}