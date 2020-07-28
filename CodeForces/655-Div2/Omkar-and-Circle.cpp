// https://codeforces.com/contest/1372/problem/D
#include<iostream>
#include<vector>
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
    int n;
    cin>>n;
    vector<ll>pref(n+1, 0), suff(n+1, 0);
    vector<int>arr(n+1);
    ip1(arr, n);

    for(int i=1; i<=n; i++){
        pref[i] = arr[i];
        if(i>2) pref[i] += pref[i-2];
    }

    for(int i=n; i>0; i--){
        suff[i] = arr[i];
        if(i<n-1) suff[i] += suff[i+2];
    }

    ll ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans, pref[i-1]+suff[i]);
    }
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