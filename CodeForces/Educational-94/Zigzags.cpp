// https://codeforces.com/contest/1400/problem/D
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
    ip(arr, n);
    ll ans=0;

    unordered_map<ll, ll>m1;

    for(int i=0; i<n; i++){
        unordered_map<ll, ll>m2;
        for(int j=n-1; j>i; j--){
            if(m2.count(arr[i]) and m1.count(arr[j])){
                ans += m2[arr[i]]*m1[arr[j]];
            }
            m2[arr[j]]++;
        }
        m1[arr[i]]++;
    }   
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