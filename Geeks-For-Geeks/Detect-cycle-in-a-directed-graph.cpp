// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclic(int V, vector<int> adj[]){
   queue<int>q;
    vector<int>inDeg(V, 0);
    
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            inDeg[adj[i][j]]++;
        }
    }
    
    for(int i=0; i<V; i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }
    
    int ct=0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        
        for(int i=0; i<adj[top].size(); i++){
            inDeg[adj[top][i]]--;
            if(inDeg[adj[top][i]] == 0){
                q.push(adj[top][i]);
            }
        }
        ct++;
    }
    
    return !(ct==V);
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends