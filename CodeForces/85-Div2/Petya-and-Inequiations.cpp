// https://codeforces.com/contest/112/problem/C
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
    ll n,x,y;
    cin>>n>>x>>y;

    vector<ll>arr(n, 1);
    arr[0] = (y-(n-1));
    if(arr[0]<=0){
        cout<<"-1\n";
        return;
    }
    ll sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i]*arr[i];
    }

    if(sum<x){
        cout<<"-1\n";
        return;
    }
    for(ll i: arr){
        cout<<i<<endl;
    }

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