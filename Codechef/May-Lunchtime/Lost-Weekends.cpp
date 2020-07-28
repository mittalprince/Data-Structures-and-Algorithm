#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

void solve(){
    ll sum=0;
    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        sum+=x;
    }
    int p;
    cin>>p;
    sum *= p;
    if(sum>120)cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}