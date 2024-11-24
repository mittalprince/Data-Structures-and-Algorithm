// https://leetcode.com/problems/redundant-connection-ii/
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

class DSU{
    vector<int>parent, rank;
    int totalComponent;

    public:
    DSU(int n){
        totalComponent = n;
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int get(int a){
        if(parent[a] == a) return parent[a];
        return parent[a] = get(parent[a]);
    }
    void union_set(int a, int b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a] < rank[b]){
                int t = b;
                b = a;
                a = t;
            }
            parent[b] = a;
            if(rank[a]==rank[b])rank[a]++;
            totalComponent--;
        }
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    // https://leetcode.com/problems/redundant-connection-ii/discuss/141897/3ms-Union-Find-with-Explanations
    int numNodes = edges.size();
    int edgeToBeRemoved = -1, edgeMakesCycle = -1;
    vector<int>parent(numNodes+1, 0);

    for(int i=0; i<numNodes; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        if(parent[v]){
            edgeToBeRemoved = i;
            break;
        } else parent[v] = u;
    }

    DSU dsu(numNodes);
    for(int i=0; i<numNodes; i++){
        if(i == edgeToBeRemoved) continue;
        int u = edges[i][0];
        int v = edges[i][1];
        if(dsu.get(u) == dsu.get(v)){
            edgeMakesCycle = i;
            break;
        }
        dsu.union_set(u,v);
    }
    // have cycle and twoParents edge, delete first twoParents edge.
    if(edgeMakesCycle != -1 && edgeToBeRemoved != -1){
        /*
        We do union only if it is not the second parentEdge. Why?
        We assume we always remove the second parentEdge. If there is still cycle remained - that means we made the wrong choice, that is, we should remove the first parentEdge instead.


        If [[1, 2], [2, 3], [4, 3], [3, 1]], [2, 3] comes before [4, 3], we remove [4,3], then we union [1, 2], [2, 3], [3, 1], there is still cycle -- so we should remove [2, 3].
        If [[1, 2], [4, 3], [2, 3], [3, 1]], [4, 3] comes before [2, 3], we remove [2, 3], then we union [1, 2], [4, 3], [3, 1], there is not cycle -- so we should remove [2, 3].

        here while buidling graph means preparing parent vector, if we face an edge have node which has 2 parents
        we're not conisdering the same edge now [4,3] and check without this if cycle exist, then we consider wrong edge
        that why first do union and then checkl cycle + twoparent, if yes find the prev edge 
        we have v node, u we can get fro parent[v]
        */
        int v = edges[edgeToBeRemoved][1];
        int u = parent[v];
        return {u,v};
    }
    // no two parents edge, just have cycle edge
    if(edgeMakesCycle != -1){
        return edges[edgeMakesCycle];
    }
    // no cycle edge, just have two parent edge.
    if(edgeToBeRemoved != -1){
        return edges[edgeToBeRemoved];
    }

    // no redundant connection
    return {0,0};
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