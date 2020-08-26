// https://codeforces.com/contest/1400/problem/B
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
    ll p,f,sc,wc,sw,ww;
    cin>>p>>f>>sc>>wc>>sw>>ww;

    if(sw>ww){
        swap(sw,ww);
        swap(sc,wc);
    }

    ll ans=0;
    for(int i=0; i<=sc; i++){
        if(i*sw>p)continue;

        ll opt1_s = i;
        ll opt1_w = min(wc, (p-(i*sw))/ww);

        ll opt2_s = min(sc-i, f/sw);
        ll opt2_w = min(wc-opt1_w, (f-(opt2_s*sw))/ww);

        ans = max(ans, opt1_s + opt1_w + opt2_s + opt2_w) ;
    }
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