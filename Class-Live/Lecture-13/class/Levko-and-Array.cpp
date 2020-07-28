#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,k;
ll arr[2005];

bool isPossible(ll x){
    ll dp[2005]={0};

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(abs(arr[i]-arr[j]) <= (i-j)*x){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }

    ll max_transaction_occur = 0;
    for(int i=0; i<n; i++){
        max_transaction_occur = max(max_transaction_occur, dp[i]);
    }
    ll max_transaction_possible = (n-1);
    ll min_transaction = max_transaction_possible-max_transaction_occur;

    return (min_transaction <= k);
}

ll solve(){
    ll s=0;
    ll e=1000000000000;

    while(s<=e){
        ll mid = (e+s)/2;
        if(isPossible(mid)){
            e=mid-1;
        }
        else s=mid+1;
    }
    return s;
}

int main(){
    cin>>n>>k;
    for(ll i=0;i<n;i++)
		cin>>arr[i];
        
    cout<<solve()<<endl;
    return 0;
}