// Minimum Spanning Tree
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));

        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    int parent[V], weight[V];
    bool visited[V];
    
    for(int i=0; i<V; i++){
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    
    weight[0]=0;
    parent[0]=-1;
    
    function<int()>helper;
    helper = [&]()->int{
      int idx=-1;
      for(int i=0; i<V; i++){
          if(!visited[i] && (idx==-1||weight[idx]>weight[i])){
              idx=i;
          }
      }
      return idx;
    };
    
    for(int i=0; i<V-1; i++){
        int minVertex = helper();
        visited[minVertex]=true;
        for(int j=0; j<V; j++){
            if(graph[minVertex][j]!=INT_MAX && !visited[j] && weight[j]>graph[minVertex][j]){
                weight[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }
    
    int ans=0;
    for(int i=1; i<V; i++){
        ans += weight[i];
    }
    return ans;
}