// https://www.spoj.com/problems/CODEIT02/
#include<iostream>
#include<vector>
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

int n, k;
int *arr;
ll ans;

void findMaxVal(int i, int k, ll curr){
    if(i==n and k==0){
        ans = max(ans, curr);
        return;
    }
    if(i>=n or k<0)return;

    findMaxVal(i+1, k, curr);
    findMaxVal(i+1, k-1, curr^arr[i]);
}

void solve(){
    cin>>n>>k;
    arr = new int[n];
    ip(arr, n);

    ans=-inf;
    findMaxVal(0, k, 0);
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