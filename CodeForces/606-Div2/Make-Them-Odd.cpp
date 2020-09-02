// https://codeforces.com/contest/1277/problem/B
#include<iostream>
#include<vector>
#include<map>
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
    vector<ll>arr(n);
    ip(arr, n);

    map<ll, ll>m;
    for(ll i: arr){
        m[i]++;
    }

    ll ans=0;
    auto it = m.rbegin();
    for( ; it!= m.rend(); it++){
        if((it->first)%2==0){
            m[(it->first)/2] += it->second;
            m[it->first] = 0;
            ans++;
        }
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