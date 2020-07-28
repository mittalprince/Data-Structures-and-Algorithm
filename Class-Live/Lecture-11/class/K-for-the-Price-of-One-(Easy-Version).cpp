#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 200005

ll n,p,k;
ll price[MAX];

void solve(){
    cin>>n>>p>>k;
    ip(price, n);

    ll dp[MAX]={0};
    sort(price, price+n);
    ll ans=0;
    for(ll i=0; i<n; i++){
        if(i<k-1){
            dp[i] = price[i]+(i>0?dp[i-1]:0);
        }
        else if(i==k-1) dp[i] = price[i];
        else dp[i] = price[i]+dp[i-k];

        if(dp[i]<=p) ans=max(ans, i+1);
    }

    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}