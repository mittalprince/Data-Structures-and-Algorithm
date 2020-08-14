// https://codeforces.com/contest/69/problem/B
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
    int n,m;
    cin>>n>>m;
    vector<pair<int, int> >arr(1005);

    for(int i=1; i<=n; i++){
        arr[i].first = inf;
        arr[i].second = 0;
    }
    ll ans=0;

    for(int i=0; i<m; i++){
        ll l,r,t,c;
        cin>>l>>r>>t>>c;
        for(int j=l; j<=r; j++){
            if(arr[j].first>t){
                arr[j].first=t;
                arr[j].second=c;
            }
        }
    }

    for(int i=1; i<=n; i++){
        ans += arr[i].second;
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}