// https://codeforces.com/contest/302/problem/C
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
    vector<int> arr(2*n-1);
    int t=inf, neg=0;
    ll ans=0;
    for(int i=0; i<2*n-1; i++){
        cin>>arr[i];
        t = min(t, abs(arr[i]));
        ans += abs(arr[i]);
        if(arr[i]<0)neg++;
    }
    if(neg&1 and !(n&1)) ans -= 2*t;
    cout<<ans<<endl;
    return 0;
}