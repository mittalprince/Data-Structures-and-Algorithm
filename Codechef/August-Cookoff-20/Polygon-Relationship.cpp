// https://www.codechef.com/COOK121B/problems/POLYREL
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
    map<pair<int, int>, int>m;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        m[{x,y}]++;
    }

    ll sz = m.size();
    ll ans=sz;
    // cout<<"t "<<ans<<endl;
    sz >>= 1;
    while(sz>2){
        ans += sz;
        sz >>= 1;
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