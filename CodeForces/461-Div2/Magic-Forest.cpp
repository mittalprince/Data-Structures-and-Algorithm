// https://codeforces.com/contest/922/problem/B
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n-1;i++){
        for(ll j=i+1;j<=n;j++){
            ll x=i^j;
            if(x>n) continue;
            if(x>=i && x>=j){
                if(x<(i+j)){
                    ans++;
                    //cout << x << " " << i << " " << j << "\n";
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}