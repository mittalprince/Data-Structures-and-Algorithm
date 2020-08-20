// https://codeforces.com/contest/1392/problem/B
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
    ll n,k;
    cin>>n>>k;
    k--;
    ll arr[n];
    ip(arr, n);

    ll mx=-inf;
    for(ll i: arr){
        mx = max(mx, i);
    }

    for(ll &i: arr){
        i = mx-i;
    }

    k %= 2;
    if(k&1){
        ll mx=-inf;
        for(ll i: arr){
            mx = max(mx, i);
        }

        for(ll &i: arr){
            i = mx-i;
        }
    }

    for(ll i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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