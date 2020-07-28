// https://codeforces.com/contest/922/problem/C
#include<iostream>
#include<vector>
#include<set>
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

    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    set<ll>s;

    for(ll i=1; i<=k; i++){
        if(s.find(n%i)!=s.end()){
            cout<<"NO\n";
            return 0;
        }
        s.insert(n%i);
    }
    cout<<"YES\n";
    return 0;
}