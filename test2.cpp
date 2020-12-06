#include<iostream>
#include<vector>
#include<climits>
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

void solve(){
    ll n;
    cin>>n;
    ll arr[n];

    for(ll i = 0; i < n; i++){
        cin>>arr[n-i-1];
    }

    ll t = 0;
    for(ll i=1; i<n; i++) {
        t += abs(arr[i]-arr[i-1]);
    }

    ll ans = LLONG_MAX;

    ans = t - abs(arr[1]-arr[0]);
    for(ll i=1; i<n-1; i++) {
        ans = min(ans, t + abs(arr[i+1]-arr[i-1])-abs(arr[i]-arr[i-1])-abs(arr[i+1]-arr[i]));
    }

    ans = min(ans, t - abs(arr[n-1]-arr[n-2]));
    cout<<ans<<endl;
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