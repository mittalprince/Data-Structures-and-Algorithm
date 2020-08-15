// https://codeforces.com/contest/1285/problem/C
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

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

void solve(){
    ll x;
    cin>>x;

    ll ans;
    for(ll i=1; i*i<=x; i++){ // find all factors of x and check lcm of x/i and i if that is x
        if(x%i == 0 and lcm(x/i, i) == x){
            ans=i;
        }
    }
    cout<<ans<<" "<<x/ans<<endl;
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