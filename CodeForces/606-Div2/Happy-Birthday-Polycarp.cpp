// https://codeforces.com/contest/1277/problem/A
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
    ll n;
    cin>>n;
    if(n<9){
        cout<<n<<endl;
        return;
    }

    ll ans=9;

    if(n>=(ll)(1e8) and n<=(ll)(1e9)){
        ans += n/111111111;
        n = 100000000;
    }
    if(n>=(1e7) and n<=(1e8)){
        ans += n/11111111;
        n = 10000000;
    }
    if(n>=(1e6) and n<=(1e7)){
        ans += n/1111111;
        n = 1000000;
    }
    if(n>=(1e5) and n<=(1e6)){
        ans += n/111111;
        n = 100000;
    }
    if(n>=(1e4) and n<=(1e5)){
        ans += n/11111;
        n = 10000;
    }
    if(n>=(1e3) and n<=(1e4)){
        ans += n/1111;
        n = 1000;
    }
    if(n>=(1e2) and n<=(1e3)){
        ans += n/111;
        n = 100;
    }
    if(n>=(1e1) and n<=(1e2)){
        ans += n/11;
        n = 10;
    }

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