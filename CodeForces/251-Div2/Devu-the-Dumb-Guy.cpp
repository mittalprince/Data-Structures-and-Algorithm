// https://codeforces.com/contest/439/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,x;
    cin>>n>>x;
    ll arr[n];
    ip(arr, n);

    sort(arr, arr+n);
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += (x*arr[i]);
        if(x>1) x--;
    }
    cout<<ans<<endl;
    return 0;
}