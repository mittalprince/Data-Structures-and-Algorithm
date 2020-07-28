#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 998244353


int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    ll n;
    cin>>n;

    ll a[n], b[n];
    ip(a, n);
    ip(b, n);

    for(ll i=0; i<n; i++){
        a[i] = a[i]*(i+1)*(n-i);
    }

    sort(a, a+n);
    sort(b, b+n, [&](ll A, ll B)->bool{
        return A>B;
    });
    
    ll ans=0;
    for(ll i=0; i<n; i++){
        ans += (a[i]%MOD * b[i]%MOD)%MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
    
    return 0;
}