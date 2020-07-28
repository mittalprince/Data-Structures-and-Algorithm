#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

/*
Logic: Used DSU, Kurskal

In this we use adhoc approach means initally we dont have know wehre to pit power station and where we connect
cities via wire.

So here we consider all edges means we intailly connect all gives position(cordinatoes of city) to each other.
Also we connect all cities to a special vertex 0.

Now how to approach from this.
Since we have already consider all possible cases, means we have already considered that we can connect city via city(each edge from one city to other) 
or to build a power station in city(edge via vertex 0), so now using this graph we have to find min cost to make a tree (use MST).

Here we use kruskal if there is an edge to any city via 0 then we build a power satation in that city and it will cost to build a power sattion
otherwise we connect city via wire and the cost will be to setup wire connecttion.

*/
class DSU{
    vector<ll>parent, rank;
    ll totalComponents;

    public:
    DSU(ll v){
        totalComponents = v;
        parent.resize(v); rank.resize(v);
        for(ll i=0; i<v; i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    ll get(ll a){
        if(parent[a] == a) return a;
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b]){
                swap(a,b);
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

    ll n;
    cin>>n;

    vector<pair<ll, ll> >pos(n+1);
    for(ll i=1; i<=n; i++){
        ll u,v;
        cin>>u>>v;
        pos[i] = {u,v};
    }

    vector<ll>powerStationCost(n+1), wireSetupCost(n+1);

    ip(powerStationCost, n);
    ip(wireSetupCost, n);

    vector<vector<ll> >edges;

    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            ll w = abs(pos[i].first-pos[j].first) + abs(pos[i].second - pos[j].second);
            w *= (wireSetupCost[i]+wireSetupCost[j]);
            edges.push_back({w, i, j});
        }
    }

    for(ll i=1; i<=n; i++){
        edges.push_back({powerStationCost[i], 0, i});
    }
    

    sort(edges.begin(), edges.end());

    DSU g(n+1);

    vector<ll>powerStationPos;
    vector<pair<ll, ll> >wireSetupPos;

    ll min_cost=0;

    for(ll i=0; i<edges.size(); i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            g.union_sets(u, v);
            min_cost += w;

            if(u){
                wireSetupPos.push_back({u,v});
            }
            else powerStationPos.push_back(v);
        }
    }

    cout<<min_cost<<endl;

    cout<<powerStationPos.size()<<endl;
    for(ll i: powerStationPos){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<wireSetupPos.size()<<endl;
    for(pair<ll, ll> i: wireSetupPos){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}