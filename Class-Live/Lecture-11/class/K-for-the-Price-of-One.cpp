#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 200005

ll n,p,k;
ll cost[MAX];

void solve(){
    cin>>n>>p>>k;
    ip(cost, n);
    sort(cost, cost+n);//since we have sorted i.e for any k-isze window we will pay for k-size window
    // last item price (since we have to pay for the expensive item to avail k-pay-offer) and tkae other k-1
    // items free

    ll dp[MAX]={0};
    // dp[i] -> denote total price req to buy total i items 
    ll ans=0;

    for(ll i=0; i<n; i++){
        if(i<k-1){
            dp[i] = cost[i]+(i>0?dp[i-1]:0);
        }
        else if(i==k-1){
            dp[i] = cost[i];//for first k-size window we have to pay just last item price
        }
        else{
            dp[i] = dp[i-k]+cost[i];
        }

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