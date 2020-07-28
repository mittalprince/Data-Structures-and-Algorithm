// Negative weight cycle
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

ll n,m;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, ll> > >adj;

    public:

    void addEdge(T u, T v, ll w){
        adj[u].push_back({v,w});
    }

    bool BellmanFord(T src){
        unordered_map<T, ll>dist;
        ll vertices = n;

        for(ll i=0; i<vertices; i++){
            dist[i]=INT_MAX;
        }

        dist[src]=0;

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
        
        // to detect cycle
        for(auto node: adj){
            T u = node.first;
            for(auto child: adj[u]){
                T v = child.first;
                ll w = child.second;
                if(dist[u] != INT_MAX and dist[v] > dist[u]+w){
                    // cout<<"Negative Cycle Present"<<endl;
					return true;
                }
            }
        }

//         for(ll i = 0 ; i < n ; i++){
// 			cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
// 		}
        return false;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	Graph<ll> g;
    	for(ll i = 0 ; i < m ; i++){
    		ll u,v,w;
    		cin>>u>>v>>w;
    		g.addEdge(u,v,w);
    	}
        cout<<g.BellmanFord(0)<<endl;
    }
    return 0;
}

/*
Input:
2
5 8
0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
3 3
0 1 -5 1 2 -6 2 0 -9
Output:
0
1
*/