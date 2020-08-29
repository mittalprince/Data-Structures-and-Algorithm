// https://www.codechef.com/problems/ICL1904
// https://hack.codingblocks.com/app/dcb/769
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

ll fstPower(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans *=a;
            ans %=MOD;
        }
        a *= a;
        a %= MOD;
        b>>= 1;
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll m=s.length();
    ll ans = fstPower(26, n-m);
    
    ll val = 25*m*fstPower(26, n-m-1);
    ans += val;
    ans %= MOD;

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