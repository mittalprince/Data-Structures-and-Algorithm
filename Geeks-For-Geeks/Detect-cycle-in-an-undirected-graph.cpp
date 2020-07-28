// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclic(vector<int> g[], int V){
    
    map<int, bool>visited;
    map<int, int>parent;
        
    function<bool(int)>bfs_helper;
    bfs_helper = [&](int src)->bool{
        
        queue<int>q;
        
        visited[src]=true;
        parent[src]=src;
        q.push(src);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(int v: g[top]){
                if(!visited[v]){
                    visited[v]=true;
                    parent[v]=top;
                    q.push(v);
                }
                else if(parent[top] != v){
                    return true;
                }
            }
        }
        return false;
    };
    
    
    for(int i=0; i<V; i++){
        if(!visited[i] && bfs_helper(i)) return true;
    }
    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends