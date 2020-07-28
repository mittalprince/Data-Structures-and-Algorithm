// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void tranposOfGraph(int V, vector<int>adj[], vector<int>t_adj[]){
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            t_adj[adj[i][j]].push_back(i);
        }
    } 
}

int kosaraju(int V, vector<int> adj[]){
    vector<int>t_adj[V];
    vector<int>order;
    
    vector<bool>visited(V, false);
    
    function<void()>transpose_of_graph;
    transpose_of_graph = [&](){
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                t_adj[adj[i][j]].push_back(i);
            }
        } 
    };
    
    transpose_of_graph();
    
    function<void(int)>dfs;
    dfs = [&](int src){
        visited[src]=true;
        
        for(int child: adj[src]){
            if(!visited[child])
            dfs(child);
        }
        order.push_back(src);
    };
    
    function<void(int)>dfst;
    dfst = [&](int src){
        visited[src]=true;
        
        for(int child: t_adj[src]){
            if(!visited[child])
            dfst(child);
        }
    };
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    int ans=0;
    for(int i=0; i<V; i++){
        visited[i]=false;
    }
    
    for(int i=V-1; i>=0; i--){
        if(!visited[order[i]]){
            dfst(order[i]);
            ans++;
        }
    }
    
    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends