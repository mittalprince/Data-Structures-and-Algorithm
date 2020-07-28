// Dijkstra’s
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

/*
Used to find shortest dist from a single source. It can not useful when graph contain negative weight cycle.
*/

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, ll> > >adj;

    public:

    void addEdge(T u, T v, ll w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void Dijkstra(T src, T dest){
        unordered_map<T, ll>dist;

        for(auto node:adj){
			dist[node.first] = INT_MAX;
		}

        set<pair<ll, T> >q;
        q.insert({0, src});
        dist[src]=0;

        while(!q.empty()){
            pair<ll, T>front = *q.begin();
            q.erase(q.begin());

            T node = front.second;
            ll node_dist = front.first;

            for(auto child: adj[node]){
                ll edge_dist = child.second;
                if(dist[child.first]>node_dist+edge_dist){
                    auto f = q.find({dist[child.first], child.first});
                    if(f != q.end()){
                        q.erase(f);
                    }
                    dist[child.first] = node_dist+edge_dist;
                    q.insert({dist[child.first], child.first});
                }
            }
        }

        for(auto node:adj){
			cout<<"Distance of "<<node.first<<" from "<<src<<" : "<<dist[node.first]<<endl;
		}
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll m;
	cin>>m;
	Graph<char> g;
	for(ll i = 0 ; i < m ; i++){
		char u , v;
		ll w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	g.Dijkstra('a','d');
    return 0;
}

/*
5
a b 1
a d 4
a c 8
b d 2
d c 3

Distance of c from a : 6
Distance of d from a : 3
Distance of b from a : 1
Distance of a from a : 0
*/