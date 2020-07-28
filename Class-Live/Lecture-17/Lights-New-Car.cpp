// Light’s New Car
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
 
string a,b;

ll stolli(string s, ll mod){
    ll ans=0;
    for(int i=0; i<s.length(); i++){
        ans = ((ans*10)%mod + (s[i]-'0'))%mod;
    }
    return ans;
}

ll fstPower(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans = (ans%m * a%m)%m;
        }
        a *= a;
        a %= m;
        b = b>>1;
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        ll x = stolli(a, MOD);
        ll y = stolli(b, MOD-1);
        cout<<fstPower(x,y,MOD)<<endl;
    }
    return 0;
}