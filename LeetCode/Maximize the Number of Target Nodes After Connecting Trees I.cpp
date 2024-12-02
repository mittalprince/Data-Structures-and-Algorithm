// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/
#include<iostream>
#include<vector>
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

vector<vector<int>> buildGraph(vector<vector<int>>&edges){
    int n = edges.size();
    vector<vector<int>>g(n+1);
    for(auto& it: edges){
        int u = it[0];
        int v = it[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}
int dfs(vector<vector<int>>&graph, int src, int parent, int depth, int count=1){
    if(depth<0)return 0;
    for(int child: graph[src]){
        if(child != parent) count += dfs(graph, child, src, depth-1);
    }
    return count;
}
vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    int n = edges1.size()+1;
    int m = edges2.size()+1;
    vector<vector<int>>g1 = buildGraph(edges1);
    vector<vector<int>>g2 = buildGraph(edges2);
    int ct=0;
    vector<int>ans;
    for(int i=0; i<m; i++){
        ct = max(ct, dfs(g2, i, -1, k-1));
    }
    for(int i=0; i<n; i++){
        int t = dfs(g1, i, -1, k);
        ans.push_back(t+ct);
    }
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}