// Maximum Distance
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

/*
Logic: Used Kruskal

The question is very tricky. what asked in question: we are given a undirected graph and 
we are given some special vertices.

For each special vertex we have to find another special vertex which is farthest from it.
The path from one vertex to other must be minimum and the cost of path will be the max edge weight,
coming in the path. Means 1->4 path include 2 edges with weights 2,5 then cost of path will be 5.

Now we make a MST as it already chose edges which is min in weight, hence path from one vertext to other is always min.
Since we have to find the path for every special vertex, so when we join we two components we maintain,
till now how many specialvertices are included in the MST. FOr this we use rank vector.

Rank vector include how many special vertices we have when a is supperparent.

Now the most imp which we have to understand since we have to print the cost of path for every special vertex 
and we know cost of path is nothing but the max edge weight from one vertex to other vertex path.

So when we pick ith edges vector, we get the edge which has min weight first and join then.
We perform the same task untill we have k specail verteices in the MST and when we have all k special vertices,
we print the ith edge weight for all specail vertices in the ans.

We have done this beacuse if for the current ith edge we have all special vertices then the max edge weight in MST, that 
connect all speacil vertices is ith edge weight.
*/

ll n,m,k;

class DSU{
    vector<ll>parent, rank;
    ll totalSpecialVertex;
    public:

    DSU(ll v){
        totalSpecialVertex = 0;
        parent = vector<ll>(v);
        rank = vector<ll>(v);

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
        if(a!=b){
            parent[b]=a;
            rank[a] += rank[b];
            totalSpecialVertex = max(totalSpecialVertex, rank[a]);
        }
    }

    void setRank(ll a){
        rank[a]=1;
    }

    bool includeAllSpecialVertex(){
        assert(totalSpecialVertex<=k);

        return (totalSpecialVertex==k);
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>k;
    vector<vector<ll> >edges;

    DSU g(n+1);

    ll specialVertices[k];
    for(ll i=0; i<k; i++){
        cin>>specialVertices[i];
        g.setRank(specialVertices[i]);
    }

    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(), edges.end());
    
    ll max_weight=0;

    for(ll i=0; i<m; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];
        if(g.get(u) != g.get(v)){
            g.union_sets(u,v);
            if(g.includeAllSpecialVertex()){
                max_weight=w;
                break;
            }
        }
    }

    for(ll i=0; i<k; i++){
        cout<<max_weight<<" ";
    }
    cout<<endl;
    return 0;
}