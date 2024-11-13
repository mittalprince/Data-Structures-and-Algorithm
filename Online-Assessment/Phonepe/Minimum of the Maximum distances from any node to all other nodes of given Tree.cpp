/*
We have a city in the form of a tree. Every Node has a house. I want to buy a house such that the maximum distance to any other house is minimized.

https://leetcode.com/discuss/interview-question/356378/
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

// TC -> O(N^2) -> doing dfs O(N) for each node
void dfs(vector<int> &d, int node, vector<vector<int>> &adj, int dist){
    d[node] = dist;
    for (auto child : adj[node]){
        if (dist + 1 < d[child])
            dfs(d, child, adj, dist + 1);
    }
}

int minDist(int N, vector<vector<int>> &edges){
    int ans = INT_MAX;

    vector<vector<int>> adj(N + 1);
    for (auto u : edges){
        adj[u[0]].push_back(u[1]);
        adj[u[1]].push_back(u[0]);
    }

    for (int i = 1; i <= N; i++){
        vector<int> d(N + 1, INT_MAX);
        dfs(d, i, adj, 0);
        int dist = 0;
        for (int j = 1; j <= N; j++)
            dist = max(dist, d[j]);
        ans = min(ans, dist);
    }
    return ans;
}

int main(){
    int N = 4;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}};

    cout << minDist(N, edges);
    return 0;
}

/*
Optimised
find diameter of tree > thats critical part to get this
https://leetcode.ca/2019-04-28-1245-Tree-Diameter/
then middle node of diameter will be the ideal node -> do bfs to find min dist
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to perform BFS and return the farthest node and distances from the start node
pair<int, vector<int>> bfs(int start, const vector<vector<int>>& tree) {
    int n = tree.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    int farthest_node = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                farthest_node = v;
            }
        }
    }
    return {farthest_node, dist};
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // Step 1: Find the diameter endpoints
    auto [A, dist_from_A] = bfs(0, tree);
    auto [B, dist_from_B] = bfs(A, tree);

    // Step 2: Compute the minimum of maximum distances
    int min_max_distance = n;
    for (int i = 0; i < n; ++i) {
        int max_distance = max(dist_from_A[i], dist_from_B[i]);
        min_max_distance = min(min_max_distance, max_distance);
    }

    cout << min_max_distance << endl;
    return 0;
}
