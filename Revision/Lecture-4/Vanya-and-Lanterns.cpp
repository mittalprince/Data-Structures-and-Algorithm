// https://codeforces.com/contest/492/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
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

    ll n,l;
    cin>>n>>l;
    vector<ll> arr(n);
    ip(arr, n);

    sort(arr.begin(), arr.end());
    double opt1 = arr[0]-0;
    double opt3 = l-arr[n-1];

    ll diff=0;
    for(ll i=0; i<n-1; i++){
        diff = max(diff, arr[i+1]-arr[i]);
    }
    double opt2 = (double)diff/(double)2;
    double ans = max(opt1, max(opt2, opt3));
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}