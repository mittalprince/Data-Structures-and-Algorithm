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
#define MAX 100005

vector<pair<ll, ll> >adj[MAX];
vector<ll>leafNodeCount(MAX);
vector<ll>edgeW(MAX);
ll n, S;

ll dfs(ll src, ll parent){
    // find one leaf node (Base case)
    if(adj[src].size()==1 and adj[src][0].first == parent)return 1;
    ll ans=0;

    for(pair<ll,ll>child: adj[src]){
        if(child.first == parent)continue;
        leafNodeCount[child.first] = dfs(child.first, src);
        edgeW[child.first] = child.second;
        ans += leafNodeCount[child.first];
    }
    return ans;
}

ll diff(ll i){
    return (edgeW[i]*leafNodeCount[i] - (edgeW[i]/2)*leafNodeCount[i]);
}

void solve(){
    cin>>n>>S;

    for(int i=0; i<n; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
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