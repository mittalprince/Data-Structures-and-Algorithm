// https://codeforces.com/contest/385/problem/A
#include<iostream>
#include<vector>
#include<climits>
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
    int n,c;
    cin>>n>>c;
    int arr[n];
    ip(arr, n);

    int ans=-inf;
    for(int i=0; i<n-1; i++){
        // cout<<arr[i+1]<<" "<<arr[i]<<endl;
        ans = max(ans, arr[i]-arr[i+1]);
    }
    ans -= c;
    if(ans<0)ans=0;
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}