// Prims
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<list>
#include<functional>
#include<algorithm>
#include<climits>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define ppi pair <ll, ll>

/*
In Prims we works on Vertex intead of edges as we did in Kruskal.
Here we maintain three thinf
1. vertex include in MST or not. Snce we have to include all vertex we run a loop of V times.
2. Parent of ith Vertex
3. Weight of ith vertex if we include it into MST

Now we pick vertex one by one which has lowest  weight till now and not consider before. Include it
into MST and update the weight of all its child (if possible).

For the starting node we set weight to 0 so that it will be picked first (as weight[start]=0)
*/

class Graph{
    ll V;
    list<ppi> *adj;

    public:

    Graph(ll v){
        V = v;
        adj = new list<ppi>[v];
    }

    void addEdge(ll u, ll v, ll w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void Prims(){
        unordered_map<ll, bool>visited; // store whether the node is included in MST ot not
        unordered_map<ll, ll>parent, weight; // store parent and wieght of ith node

        // steo 1 is make all node weight is Infinity
        for(ll i=0; i<V; i++){
            visited[i]=false;
            weight[i]=INT_MAX;
        }

        function<ll()>findMinVertex;

        findMinVertex = [&]()->ll{
            ll idx=-1;

            for(ll i=0; i<V; i++){
                if(!visited[i] && (idx==-1 || weight[idx]>weight[i])){
                    idx=i;
                }
            }
            assert(idx >=0 && idx < V);
            return idx;
        };


        parent[0]=-1;
        weight[0]=0;

        // Now we consider all vertex one by one
        // Here we run loop V-1 times as after considering V-1 vertices we actually have all edges
        // means the MST is complete so we dont need to consider last vertex 
        for(ll i=0; i<V-1; i++){
            // at each step with the available vertex with min weight
            ll minVertex = findMinVertex();
            visited[minVertex]=true;// include it into MST
            for(auto child: adj[minVertex]){ // now update the weight of all its child
                if(!visited[child.first]){
                    if(weight[child.first]>child.second){
                        weight[child.first] = child.second;
                        parent[child.first] = minVertex; 
                    }
                }
            }
        }

        ll min_cost=0;

        for(ll i=1; i<V; i++){
            min_cost += weight[i];
            cout<<i<<" vertext is connected with "<<parent[i]<<" with weight "<<weight[i]<<endl;
        }

        cout<<"MST weight is "<<min_cost<<endl;
    }   
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;

	Graph g(n);
	for(ll i=0; i<m; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	g.Prims();
    
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

1 vertext is connected with 0 with weight 4
2 vertext is connected with 1 with weight 8
3 vertext is connected with 2 with weight 7
4 vertext is connected with 3 with weight 9
5 vertext is connected with 2 with weight 4
6 vertext is connected with 5 with weight 2
7 vertext is connected with 6 with weight 1
8 vertext is connected with 2 with weight 2
MST weight is 37
*/