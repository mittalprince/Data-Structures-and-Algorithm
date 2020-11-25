//https://codeforces.com/contest/1454/problem/D
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

vector<ll> factors;

void getFactors(ll n){
    for(ll i=2; i<=sqrt(n); i++){
        while(n%i==0){
            factors.push_back(i);
            n /= i;
        }
    }
    if(n>1){
        factors.push_back(n);
    }
}

void solve(){
    ll n;
    cin>>n;

    getFactors(n);
    unordered_map<ll, ll>freq;

    for(ll i:factors){
        freq[i]++;
    }

    ll mx=0, val=-1;
    for(auto it: freq){
        if(it.second>mx){
            mx=it.second;
            val = it.first;
        }
    }

    cout<<mx<<endl;
    while(mx!=1){
        cout<<val<<" ";
        n /= val;
        mx--;
    }
    cout<<n<<endl;
    factors.clear();
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