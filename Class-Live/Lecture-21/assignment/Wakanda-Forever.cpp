#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<unordered_map>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

ll n,m,d;

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

void solve(){
    cin>>n>>m>>d;

    vector<bool>valid_city(n+1, 0);
    ll total_valid_city=0;
    for(ll i=1; i<=n; i++){
        ll x;
        cin>>x;
        valid_city[i]= x?1:0;
        total_valid_city += valid_city[i];
    }

    vector<vector<ll> >edges;

    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(), edges.end());

    DSU g(n+1);
    ll ans=0, total_city_considered_edges=0;

    for(ll i=0; i<m; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(!valid_city[u] || !valid_city[v])continue;

        if(g.get(u) != g.get(v)){
            total_city_considered_edges++;
            ans += w;
            g.union_sets(u, v);
        }
        if(total_city_considered_edges == total_valid_city-1)break;
    }

    ans += max(0ll,(total_valid_city-1-total_city_considered_edges)*d);
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