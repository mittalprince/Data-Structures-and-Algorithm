#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class DSU{
    vector<ll>parent, rank;
    ll V;

    public:
    DSU(ll v){
        parent = vector<ll>(v);
        rank = vector<ll>(v, 0);
        V = v;
        for(ll i=0; i<V; i++){
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    DSU g(n+1);

    map<pair<ll, ll>, bool>visited;
    vector<vector<ll> >edges;

    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        edges.push_back({1,u,v});
        visited[{u,v}]=true;
    }
    
    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            if(!visited[{i,j}]){
                edges.push_back({0,i,j});
            }
        }
    }
    sort(edges.begin(), edges.end());
    ll ans=0;

    for(ll i=0; i<m; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            ans += w;
            g.union_sets(u, v);
        }
        if(g.isConsideredAllVertice())break;
    }

    cout<<ans<<endl;
    return 0;
}