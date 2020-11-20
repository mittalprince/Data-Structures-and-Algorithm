//https://codeforces.com/contest/1452/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
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

void solve(){
    int n;
    cin>>n;
    ll arr[n];
    ip(arr, n);

    sort(arr, arr+n);
    ll sum=0;
    for(ll i:arr)sum+=i;

    ll N=n-1;
    ll mean = ceil(sum/(double)N);
    ll ans = mean*(n-1);

    if(arr[n-1]>mean){
        ans = arr[n-1]*(n-1);
    }
    cout<<ans-sum<<endl;
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