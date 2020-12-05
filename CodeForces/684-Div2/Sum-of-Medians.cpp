//https://codeforces.com/contest/1440/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
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
    int n,k;
    cin>>n>>k;
    vector<ll>arr(n*k);
    ip(arr, n*k);

    ll ans=0;
    ll N = n*k;

    for(int i=N-((n/2)+1); i>=0 and k>0; k--, i -= (n/2+1)){
        ans += arr[i];
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