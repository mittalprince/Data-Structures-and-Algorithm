#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<cassert>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 200005

vector<vector<ll> >edges;
ll *cost;

class DSU{
    vector<int>parent, rank;
    int V, totalComponents;
    public:

    DSU(int v){
        V = v;
        totalComponents=v;
        parent.resize(V+1);
        rank.resize(V+1);

        for(int i=0; i<=V; i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int get(int a){
        if(parent[a]==a)return a;
        return parent[a] = get(parent[a]);
    }

    void union_sets(int a, int b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b] =a;
            if(rank[a]==rank[b])rank[a]++;
            totalComponents--;
        }
    }

    bool isCondsiderAllVertices(){
        return totalComponents==1;
    }
};


int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;

    cost = new ll[n+1];
    
    ll min_edge_cost=LLONG_MAX, min_edge_idx=-1;// used for optimization
    // here we find the vertex whose val is least, because we will make an edge from all vertices to this edges.
    for(int i=1; i<=n; i++){
        cin>>cost[i];
        if(cost[i]<min_edge_cost){
            min_edge_cost = cost[i];
            min_edge_idx=i;
        }
    }

    for(int i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
    }
    // here we make all cobination but it gives MLE,
    // to handle this we make edge with vertext that has least val, thus we have inserted all edges connected to a single vertex.
    for(int i=1; i<=n; i++){
        if(i==min_edge_idx)continue;
        edges.push_back({cost[i]+cost[min_edge_idx], min_edge_idx, i});
    }

    sort(edges.begin(), edges.end());
    ll min_cost=0;

    DSU g(n);

    for(ll i=0; i<edges.size(); i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            min_cost += w;
            g.union_sets(u, v);
        }

        if(g.isCondsiderAllVertices()) break;
    }

    cout<<min_cost<<endl;

    return 0;
}