// https://codeforces.com/contest/785/problem/C
#include<iostream>
#include<vector>
#include<climits>
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

    ll n,m;
    cin>>n>>m;

    if(n<=m){
        cout<<n<<endl;
        return 0;
    }
    ll s=0, e=INT_MAX;
    n -= m;
    ll ans=0;
    while(s<=e){
        ll mid = s+(e-s)/2;
        ll t = (mid*(mid+1))/2;
        if(t>=n){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<(m+ans)<<endl;
    return 0;
}