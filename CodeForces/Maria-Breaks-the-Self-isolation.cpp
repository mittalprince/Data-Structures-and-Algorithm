#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n;
    cin>>n;
    ll arr[n];

    ip(arr, n);
    sort(arr, arr+n);

    ll ans=1;
    ll i=0;
    for(i=n-1; i>=0; i--){
        if(arr[i] > i+1){
            continue;
        }
        break;
    }
    cout<<i+2<<endl;
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