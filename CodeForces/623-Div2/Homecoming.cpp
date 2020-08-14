// https://codeforces.com/contest/1315/problem/B
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
    int a,b,p;
    string s;
    cin>>a>>b>>p>>s;

    char prev='C';
    ll cost=0;
    int ans=s.length();
    for(int i=s.length()-2; i>=0; i--){
        if(s[i] != prev){
            cost+=(s[i]=='A')?a:b;
        }
        if(cost<=p)ans=i+1;
        else break;
        prev=s[i];
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