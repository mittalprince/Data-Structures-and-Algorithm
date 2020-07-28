// https://codeforces.com/contest/276/problem/D
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    ll l,r;
    cin>>l>>r;
    int i;

    for(i=63; i>=0; i--){
        if((l&(1ll<<i))^(r&(1ll<<i))){
            break;
        }
    }
    i++;
    ll ans = (1ll<<i)-1;
    cout<<ans<<endl;
    return 0;
}