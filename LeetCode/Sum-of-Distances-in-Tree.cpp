// https://leetcode.com/problems/sum-of-distances-in-tree/
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

/*
https://leetcode.com/problems/sum-of-distances-in-tree/Figures/834/sketch1.png

Then, as illustrated in the diagram, the answer for xx in the entire tree, 
is the answer of xx on XX "x@X", plus the answer of yy on YY "y@Y", 
plus the number of nodes in YY "#(Y)". The last part "#(Y)" is specifically because for any node z in Y, 
dist(x, z) = dist(y, z) + 1.

By similar reasoning, the answer for yy in the entire tree is ans[y] = x@X + y@Y + #(X). Hence, 
for neighboring nodes xx and yy, ans[x] - ans[y] = #(Y) - #(X).

Root the tree. For each node, consider the subtree Snode of that node plus all descendants. 
Let count[node] be the number of nodes in Snode, and stsum[node] ("subtree sum") be the sum of the distances 
from node to the nodes in Snode.

We can calculate count and stsum using a post-order traversal, 
where on exiting some node, the count and stsum of all descendants of this node is correct, 
and we now calculate count[node] += count[child] and stsum[node] += stsum[child] + count[child].

This will give us the right answer for the root: ans[root] = stsum[root].

Now, to use the insight explained previously: if we have a node parent and it's child child, 
then these are neighboring nodes, and so ans[child] = ans[parent] - count[child] + (N - count[child]). 
This is because there are count[child] nodes that are 1 easier to get to from child than parent, 
and N-count[child] nodes that are 1 harder to get to from child than parent.
*/

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans(N, 0), ct(N, 1);
    vector<int>adj[N];

    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    function<void(int, int)>dfs1; // post order
    dfs1 = [&](int src, int parent){
        for(int child: adj[src]){
            if(child != parent){
                dfs1(child, src);
                ct[src] += ct[child];
                ans[src] += ans[child]+ct[child];
            }
        }  
    };

    function<void(int, int)>dfs2; // pre order
    dfs2 = [&](int src, int parent){
        for(int child: adj[src]){
            if(parent != child){
                ans[child] = ans[src] - ct[child] + (N-ct[child]);
                dfs2(child, src);
            }
        }  
    };

    dfs1(0,0);
    dfs2(0,0);

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}