//https://www.codechef.com/COOK124B/problems/IPCCERT
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
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<ll>> arr(n, vector<ll>(k + 1));
     ll ans = 0;

    for(ll i=0; i<n; i++){
        ll sum=0;
        for(ll j=0; j<=k; j++){
            cin>>arr[i][j];
            if(j<k)sum += arr[i][j];
        }
        if(sum>=m and arr[i][k]<=10)ans++;
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