// https://www.hackerearth.com/problem/algorithm/lcmk-a8c3e378/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
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
#define MAX 1000005

int Prime[MAX]={0};

// find the smallest factors of each no upto MAX
void sieve(){
    Prime[0]=Prime[1]=1;
    for(int i=2; i<MAX; i++){
        if(Prime[i]==0){
            for(int j=2*i; j<MAX; j+=i){
                if(Prime[j]==0){
                    Prime[j]=i;
                }
            }
            Prime[i]=i;
        }
    }
}

ll fstPower(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;

        b >>= 1;
    }

    return ans;
}

void solve(){
    unordered_map<ll, ll>factors;
    ll n,m,k;
    cin>>n>>m>>k;

    ll arr[n];
    ip(arr, n);

    for(ll i: arr){
        unordered_map<ll, ll>t;

        ll num = i;
        while(num>1){
            ll fac = Prime[num];
            t[fac]++;

            num /= fac;
        }

        for(auto it: t){
            factors[it.first] = max(factors[it.first], it.second);
        }
    }

    ll ans=1;

    for(auto it: factors){
        // cout<<it.first<<" "<<it.second<<endl;
        // cout<<pow(it.first, it.second*k)<<endl;
        // ans *= pow(it.first, it.second*k);
        ans *= fstPower(it.first, it.second*k, m);
        ans %= m;
    }

    cout<<ans<<endl;
}

int main(){

    fstIO;
    
    int t;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}