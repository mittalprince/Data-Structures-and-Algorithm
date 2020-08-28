#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// It works on edges concept, here we sort edges by weight and pick those which one by one which is min and 
// include in into MST.
// In Kruskal we Used DU logic. Insert the given edges into MST when the edge vertex parent are not same means they are not 
// in single component , union them and add their cost.

class DSU{
    vector<ll>parent, rank;
    ll totalComponents;

    public:

    DSU(ll n){
        totalComponents = n;
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i]=i;rank[i]=0;
        }
    }

    ll get(ll a){
        if(parent[a] == a)return parent[a];
        return parent[a] = get(parent[a]);
    }

    void union_set(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
            totalComponents--;
        }
    }  
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    vector<vector<ll> >edges;

    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    
    sort(edges.begin(), edges.end());

    DSU g(n);

    map<ll, list<pair<ll, ll> > >adj;
    ll min_weight=0;

    for(ll i=0; i<m; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            min_weight += w;
            g.union_set(u, v);
            adj[u].push_back({v, w});
        }
    }

    cout<<"MST Weight is "<<min_weight<<endl;
    for(auto node: adj){
        for(auto child: adj[node.first]){
            cout<<"There is an edge from "<<node.first<<" to "<<child.first<<" with weight "<<child.second<<endl;
        }
    }
    
    return 0;
}

/*
9 14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8 
1 2 8
3 4 9
5 4 10
1 7 11 
3 5 14

MST Weight is 37
There is an edge from 0 to 1 with weight 4
There is an edge from 0 to 7 with weight 8
There is an edge from 2 to 5 with weight 4
There is an edge from 2 to 3 with weight 7
There is an edge from 3 to 4 with weight 9
There is an edge from 6 to 5 with weight 2
There is an edge from 7 to 6 with weight 1
There is an edge from 8 to 2 with weight 2
*/