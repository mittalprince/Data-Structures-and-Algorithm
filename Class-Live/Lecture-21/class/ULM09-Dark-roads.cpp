#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

ll n,m;

class DSU{
    vector<ll>parent, rank;
    ll totalComponents;

    public:
    DSU(ll v){
        totalComponents = v;
        parent = vector<ll>(v);
        rank = vector<ll>(v, 0);

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
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            if(rank[a] == rank[b])rank[a]++;
            totalComponents--;
        }
    }

    bool isConsiderAllVertices(){
        return totalComponents==1;
    }
};

void solve(){

    ll total_cost=0, min_cost=0;

    vector<vector<ll> >edges;

    for(ll i=0; i<m; i++){
         ll u,v,w;
         cin>>u>>v>>w;
         edges.push_back({w,u,v});
         total_cost += w;
    }

    sort(edges.begin(), edges.end());
    DSU g(n);

    for(ll i=0; i<m; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            min_cost += w;
            g.union_sets(u,v);
        }

        if(g.isConsiderAllVertices())break;
    }

    cout<<total_cost-min_cost<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    while(n and m){
        solve();
        cin>>n>>m;
    }
    return 0;
}