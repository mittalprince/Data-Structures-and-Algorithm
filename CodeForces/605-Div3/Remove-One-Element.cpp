// https://codeforces.com/contest/1272/problem/D
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

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr, n);

    int ans=0;
    vector<int>right(n, 1), left(n, 1);
    for(int i=n-2; i>=0; i--){
        if(arr[i+1]>arr[i])right[i] = right[i+1]+1;
        ans = max(ans, right[i]);
    }

    for(int i=1; i<n; i++){
        if(arr[i]>arr[i-1])left[i] = left[i-1]+1;
        ans = max(ans, left[i]);
    }

    for(int i=0; i<n-2; i++){
        if(arr[i]<arr[i+2]){
            ans = max(ans, left[i]+right[i+2]);
        }
    }

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