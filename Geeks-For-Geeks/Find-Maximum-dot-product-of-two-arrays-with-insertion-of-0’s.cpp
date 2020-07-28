#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n,m;
    cin>>n>>m;
    ll arr[n], brr[m];
    ip(arr, n);
    ip(brr, m);

    vector<vector<ll> > dp(m+1, vector<ll>(n+1, 0));

    for(int i=1; i<=m; i++){
        for(int j=i; j<=n; j++){
            dp[i][j] = max(dp[i-1][j-1] + arr[j-1]*brr[i-1], dp[i][j-1]);
        }
    }

    cout<<dp[m][n]<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}