// https://codeforces.com/contest/1391/problem/C
#include<iostream>
#include<vector>
#include<cmath>
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

ll fstPow(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
 
        b >>= 1;
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;

    ll ans=1;
    for(int i=1; i<=n; i++){
        ans *= i;
        ans %= MOD;
    }
    
    ll invalid_permute = fstPow(2, n-1);
    ans -= invalid_permute;
    ans = (ans+MOD)%MOD;
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}