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
Used to find shortest dist from a single source, It can handle neg weightc cycle.
For this we releax verrices in this. 

Run loop from V-1 time and update the dist if possible

Now again try one more time to update the dist if its updated menas cycle present otherwise not
TC -> VE
SC -> V
*/

/*
In the worst-case scenario, a shortest path between two vertices can have at most N-1 edges, where N is the number of vertices. This is because a simple path in a graph with N vertices can have at most N-1 edges, as it’s impossible to form a closed loop without revisiting a vertex.

By relaxing edges N-1 times, the Bellman-Ford algorithm ensures that the distance estimates for all vertices have been updated to their optimal values, assuming the graph doesn’t contain any negative-weight cycles reachable from the source vertex. If a graph contains a negative-weight cycle reachable from the source vertex, the algorithm can detect it after N-1 iterations, since the negative cycle disrupts the shortest path lengths.

In summary, relaxing edges N-1 times in the Bellman-Ford algorithm guarantees that the algorithm has explored all possible paths of length up to N-1, which is the maximum possible length of a shortest path in a graph with N vertices. This allows the algorithm to correctly calculate the shortest paths from the source vertex to all other vertices, given that there are no negative-weight cycles.

As previously discussed, achieving the single source shortest paths to all other nodes takes N-1 relaxations. If the N’th relaxation further reduces the shortest distance for any node, it implies that a certain edge with negative weight has been traversed once more. It is important to note that during the N-1 relaxations, we presumed that each vertex is traversed only once. However, the reduction of distance during the N’th relaxation indicates revisiting a vertex.
*/
ll n,m;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, ll> > >adj;

    public:

    void addEdge(T u, T v, ll w){
        adj[u].push_back({v,w});
    }

    void BellmanFord(T src){
        unordered_map<T, ll>dist;
        ll vertices = n;

        for(ll i=0; i<vertices; i++){
            dist[i]=INT_MAX; // intially set dist to inf
        }

        dist[src]=0;
        // relaxation fof vertices or v-1 times
        for(ll i=0; i<vertices-1; i++){
            for(auto node: adj){
                T u = node.first;
                for(auto child: adj[u]){
                    T v = child.first;
                    ll w = child.second;
                    if(dist[u] != INT_MAX and dist[v] > dist[u]+w){
                        dist[v] = dist[u]+w;
                    }
                }
            }
        }
        
        // after relaxing vetrices v-1 times, we check for for negative cycle
		// so relaxing one more time to detect cycle
        for(auto node: adj)
        {
            T u = node.first;
            for(auto child: adj[u]){
                T v = child.first;
                ll w = child.second;
                if(dist[u] != INT_MAX and dist[v] > dist[u]+w){
                    cout<<"Negative Cycle Present"<<endl;
					return;
                }
            }
        }

        for(ll i = 0 ; i < n ; i++){
			cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
		}
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	cin>>n>>m;
	Graph<ll> g;
	for(ll i = 0 ; i < m ; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
    g.BellmanFord(0);
    return 0;
}

/*
6 8
0 1 1
0 2 2
2 1 -2
1 3 1
3 4 2
2 4 4
3 5 1 
4 5 0

Distance of 0 from 0 is 0
Distance of 1 from 0 is 0
Distance of 2 from 0 is 2
Distance of 3 from 0 is 1
Distance of 4 from 0 is 3
Distance of 5 from 0 is 2
*/