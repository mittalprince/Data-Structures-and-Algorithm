// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
int* topoSort(int V, vector<int> adj[]) {
    int inDeg[V];
    for(int i=0; i<V; i++){
        inDeg[i]=0;
    }
    
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            inDeg[adj[i][j]]++;
        }
    }
    
    queue<int>q;
    int *ans = new int[V];
    int idx=0;
    
    for(int i=0; i<V; i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans[idx++]=front;
        for(int i=0; i<adj[front].size(); i++){
            inDeg[adj[front][i]]--;
            if(inDeg[adj[front][i]]==0){
                q.push(adj[front][i]);
            }
        }
    } 
    
    return ans;
}

void topo(int i, int V, int vis[], vector<int> adj[], stack<int> &s)
{
    vis[i] = 1;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!vis[adj[i][j]])
            topo(adj[i][j], V, vis, adj, s);
    }
    s.push(i);
}
int *topoSort(int V, vector<int> adj[])
{
    stack<int> s;
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            topo(i, V, vis, adj, s);
    }
    int *a = ((int *)malloc(sizeof(int) * V));
    int j = 0;
    while (!s.empty())
    {
        a[j] = s.top();
        s.pop();
        j++;
    }
    return a;
}
