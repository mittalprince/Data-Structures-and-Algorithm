#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll func(ll n, ll k){
    if(n==0) return 0;
    ll res = n/k;
    ll opt1 = func(n/k, k);
    ll opt2 = (n*(n+1)/2ll) - ((res*(res+1)/2ll)*k);

    return opt1+opt2;
}

void solve(){
    ll n,k;
    cin>>n>>k;

    assert(n<=1e9);
    assert(k>=2 && k<=1e9);

    cout<<func(n, k)<<endl;
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