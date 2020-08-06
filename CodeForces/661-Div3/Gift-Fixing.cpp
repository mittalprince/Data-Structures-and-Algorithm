// https://codeforces.com/contest/1399/problem/B
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
    int n;
    cin>>n;

    vector<int>a(n), b(n);
    int mina=INT_MAX, minb=INT_MAX;

    for(int i=0; i<n; i++){
        cin>>a[i];
        mina = min(mina, a[i]);
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        minb = min(minb, b[i]);
    }
    
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += max(a[i]-mina,b[i]-minb);
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