#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    ll arr[n];
    ip(arr, n);

    for(int i=0; i<n-1; i++){
        if(arr[i+1]-arr[i] > k){ // need to make the diff smaller, so add blocks from bag to ith col
            m -= (arr[i+1]-arr[i]-k); // amt that need to be added;

            if(m<0){
                cout<<"No\n";
                return;
            }
        }
        else{
            // 1. here we check if arr[i+1]<k (arr[i+1]-k<0) means whatever we sub from arr[i+1] it will be valid jump, 
            // so in this case we add whole ith col into bag so take 0ll
            // 2. otherwise we check how much we need to dec from arr[i] to make move valid and rem add into bag
            ll max_block_add = max(0ll, arr[i+1]-k);
            m += (arr[i]-max_block_add); // find the amt that we can from ith col to bag
        }
    }
    cout<<"Yes\n";
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}