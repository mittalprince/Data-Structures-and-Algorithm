//https://codeforces.com/contest/1409/problem/A
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
    int a,b;
    cin>>a>>b;
    ll diff = abs(a-b);
    if(diff==0){
        cout<<"0\n";
        return;
    }
    if(diff<=10){
        cout<<"1\n";
        return;
    }
    ll ans=0;
    for(int i=10; i>=1; i--){
        ll v = diff/i;
        diff -= (v*i);
        ans += v;
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