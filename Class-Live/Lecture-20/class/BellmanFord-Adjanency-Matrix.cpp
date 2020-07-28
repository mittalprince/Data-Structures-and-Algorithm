#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

int V=5, E=8;

void BellmanFord(int graph[][3], int src){
    vector<int>dist(V, INT_MAX);

    dist[src]=0;
    for(int i=0; i<V-1; i++){
        for(int j=0; j<E; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int w = graph[j][2];

            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    
    for(int j=0; j<E; j++){
        int u = graph[j][0];
        int v = graph[j][1];
        int w = graph[j][2];

        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
            cout<<"Graph contain negative cycle\n";
            return;
        }
    }

    for(int i=0; i<V; i++){
        cout<<"Distance of node "<<i<<" from src vertex "<<src<<" is "<<dist[i]<<endl; 
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int graph[][3] = { {0, 1, -1},
              {0, 2, 4},
              {1, 2, 3},
              {1, 3, 2},
              {1, 4, 2},
              {3, 2, 5},
              {3, 1, 1},
              {4, 3, -3} };

    BellmanFord(graph, 0);
    return 0;
}

/*
Distance of node 0 from src vertex 0 is 0
Distance of node 1 from src vertex 0 is -1
Distance of node 2 from src vertex 0 is 2
Distance of node 3 from src vertex 0 is -2
Distance of node 4 from src vertex 0 is 1
*/