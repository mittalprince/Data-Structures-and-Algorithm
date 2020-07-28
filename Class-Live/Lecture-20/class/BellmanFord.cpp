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