// https://codeforces.com/contest/1009/problem/C
#include<iostream>
#include<vector>
#include<iomanip>
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

/*
Logic: x will always be add into arr[i]
now for d*|i-j| ke liye
if d is pos then we will chose 0 as i, so the (i-j) will be like 1,2,3,4..(n-1) -> n*(n-1)/2;
if d is neg then we chose n/2 as i so add its elft and right sum into neg 
*/
void solve(){
    ll n,m;
    cin>>n>>m;

    ll pos = n*ll(n-1)/2;
    ll neg = 0;
    if(n&1){
        ll t=n/2;
        neg += t*ll(t+1)/2;
        neg *= 2;
    }
    else{
        ll a = (n/2);
        neg += a*ll(a-1)/2 + a*ll(a+1)/2;
    }

    ll ans=0;
    for(int i=0; i<m; i++){
        ll x,d;
        cin>>x>>d;
        ans += x*(ll)n;
        if(d<0){
            ans += neg*d;
        }   
        else{
            ans += pos*d;
        }
    }

    double res = (double)ans/n;
    cout<<fixed<<setprecision(15)<<res<<endl;
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