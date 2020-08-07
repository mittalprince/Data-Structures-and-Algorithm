// https://codeforces.com/contest/1393/problem/C
#include<iostream>
#include<vector>
#include<unordered_map>
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
    ll n;
    cin>>n;

    vector<ll>arr(n);
    unordered_map<ll,ll>m;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }

    ll mx=0;
    for(auto it: m){
        mx = max(it.second, mx);
    }
    ll ct=0;
    for(auto it:m){
        if(mx == it.second)ct++;
    }

    ll k = n-(ct*mx); // max_freq is mx and total elemnt of same freq is ct, so rem elemnt is n-(ct*mx);
    // Now inn k element ko mx freq ke beech distribute karna hai so (k/(mx-1))
    // and add ct-1 as we can add them into k elemnt lis 1 2 5 4 1 7 8 4 -> so gap is 3 as we also use 4
    cout<<(k/(mx-1))+(ct-1)<<endl;
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