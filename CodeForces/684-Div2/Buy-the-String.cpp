//https://codeforces.com/contest/1440/problem/A
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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;

    string s;
    cin>>s;
    int one=0, zero=0;
    for(char i:s){
        if(i=='1')one++;
        else zero++;
    }
    ll ans=0;
    if(a+c<b){
        zero += one;
        ans += one*c;
        one=0;
    }
    else if(b+c<a){
        one += zero;
        ans += zero*c;
        zero = 0;
    }

    ans += a*zero + b*one;
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