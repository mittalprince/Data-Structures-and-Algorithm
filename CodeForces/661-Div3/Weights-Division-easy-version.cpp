// https://codeforces.com/contest/1399/problem/E1
#include<iostream>
#include<vector>
#include<queue>
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
#define ppi pair<ll,ll>

vector<ppi>adj[MAX];
vector<ll>leafNodeCount(MAX);
vector<ll>edgeW(MAX);
ll n, S, sum;

ll dfs(ll src, ll parent){
    // find one leaf node (Base case)
    if(adj[src].size()==1 and adj[src][0].first == parent)return 1;
    ll ans=0;

    for(ppi child: adj[src]){
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

    for(int i=1; i<n; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dfs(0, -1);
    sum=0;
    priority_queue<ppi>pq;
    for(ll i=0; i<n; i++){
        pq.push({diff(i), i});
        sum += edgeW[i]*leafNodeCount[i];
    }

    ll ans=0;
    while(sum>S){
        ppi top = pq.top();
        pq.pop();
        ans++;
        sum -= top.first;
        edgeW[top.second] /= 2;
        pq.push({diff(top.second), top.second});
    }

    cout<<ans<<endl;
    for(ll i=0; i<=n; i++)adj[i].clear();
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