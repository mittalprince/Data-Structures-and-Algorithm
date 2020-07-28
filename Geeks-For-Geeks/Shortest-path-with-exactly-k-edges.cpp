// https://www.geeksforgeeks.org/shortest-path-exactly-k-edges-directed-weighted-graph/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf INT_MAX
#define INF 1e16
#define MOD 1000000007
#define V 4

int shortestPath(int graph[][V], int u, int v, int k){
    int dist[V][V][k+1];

    for(int e=0; e<=k; e++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                dist[i][j][e]=inf;
                
                if(e==0 and i==j){
                    dist[i][j][e]=0;
                }
                if(e==1 and graph[i][j] != inf){
                    dist[i][j][e]=graph[i][j];
                }
                if(e>1){
                    for(int a=0; a<V; a++){
                        if(graph[i][a] != inf and i!=a and j!=a and dist[a][j][e-1] != inf){
                            dist[i][j][e] = min(dist[i][j][e], graph[i][a]+dist[a][j][e-1]);
                        }
                    }
                }
            }
        }
    }

    return dist[u][v][k];
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int graph[V][V] = {{0, 10, 3, 2},
                       {inf, 0, inf, 7},
                       {inf, inf, 0, 6},
                       {inf, inf, inf, 0}};
    int u = 0, v = 3, k = 2;
    cout << "Weight of the shortest path is " << shortestPath(graph, u, v, k);
    return 0;

    return 0;
}