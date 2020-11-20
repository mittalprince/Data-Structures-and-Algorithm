//https://codeforces.com/contest/1409/problem/B
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

ll check(ll a, ll b, ll x, ll y, ll n){
    ll diff1 = a-x;
    a -= min(diff1, n);

    if(diff1<=n){
        n -= diff1;
        diff1=0;
    }
    else{
        n=0;
        diff1 -= n;
    }

    ll diff2 = b-y;
    b -= min(diff2, n);

    if(diff2<=n){
        n -= diff2;
        diff2=0;
    }
    else{
        n=0;
        diff2 -=n;
    }

    return a*b;
}

void solve(){
    ll a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;

    ll opt1 = check(a,b,x,y,n);
    ll opt2 = check(b,a,y,x,n);

    cout<<min(opt1, opt2)<<endl;
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