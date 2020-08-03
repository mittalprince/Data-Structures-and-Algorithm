// https://atcoder.jp/contests/abc174/tasks/abc174_c
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

    ll n;
    cin>>n;
    
    if(n%2 ==0 or n%5 == 0){
        cout<<"-1\n";
        return 0;
    }
    ll curr = 7%n;
    ll ans=1;

    while(curr != 0){
        curr = curr*10+7;
        curr %= n;
        ans++;
    }

    cout<<ans<<endl;
    return 0;
}
