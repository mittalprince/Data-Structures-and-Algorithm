#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<unordered_map>
#include<cstring>
#include<list>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 200005

ll n,m;
vector<pair<ll, ll> > adj[MAX];
vector<ll>one_ct(MAX, 0);
ll max_weight = 0;

class DSU{
    vector<ll>parent, rank;
    ll V;

    public:
    DSU(ll v){
        parent = vector<ll>(v);
        rank = vector<ll>(v, 0);
        V = v-1;
        for(ll i=0; i<v; i++){
            parent[i]=i;
        }
    }

    ll get(ll a){
        if(parent[a] == a)return a;
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b])swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
            V--;
        }
    }

    bool isConsideredAllVertice(){
        return V==1;
    }
};

void processing(){
    for(ll i=0; i<max_weight; i++){
        one_ct[i+1] += one_ct[i]/2;
        one_ct[i] %= 2;
    }

    // if carry present
    while(one_ct[max_weight]>1){
        one_ct[max_weight+1] += one_ct[max_weight]/2;
        one_ct[max_weight] %= 2;
        max_weight++;
    }

    for(ll i=max_weight; i>=0; i--){
        cout<<one_ct[i];
    }
    cout<<endl;
}

void DFS(){
    vector<bool>visited(n+1, false);
    vector<ll>ct(n+1, 0);

    function<ll(ll)>dfs_helper;
    dfs_helper = [&](ll src)->ll{
        visited[src]=true;
        ct[src]=1;

        for(auto child: adj[src]){
            ll dx = child.second;
            if(!visited[child.first]){
                ct[src] += dfs_helper(child.first);
                ll no_of_right_nodes = ct[child.first];
                ll no_of_left_nodes = n - no_of_right_nodes;
                one_ct[dx] += 1ll*no_of_left_nodes*no_of_right_nodes;
            }
        }
        return ct[src];
    };

    dfs_helper(1);
}

void solve(){
    cin>>n>>m;
    vector<vector<ll> >edges;

    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(), edges.end());

    DSU g(n+1);

    for(ll i=0; i<m; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            g.union_sets(u, v);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            max_weight = w;
        }
        if(g.isConsideredAllVertice())break;
    }

    DFS();
    processing();
}

int main(){
    fstIO

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