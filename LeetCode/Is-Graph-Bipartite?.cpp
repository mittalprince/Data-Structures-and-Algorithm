//https://leetcode.com/problems/is-graph-bipartite/
#include<iostream>
#include<vector>
#include<queue>
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

bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B

    queue<int> q; // queue, resusable for BFS

    for (int i = 0; i < n; i++)
    {
        if (color[i])
            continue; // skip already colored nodes

        // BFS with seed node i to color neighbors with opposite color
        color[i] = 1; // color seed i to be A (doesn't matter A or B)
        for (q.push(i); !q.empty(); q.pop())
        {
            int cur = q.front();
            for (int neighbor : graph[cur])
            {
                if (!color[neighbor]) // if uncolored, color with opposite color
                {
                    color[neighbor] = -color[cur];
                    q.push(neighbor);
                }

                else if (color[neighbor] == color[cur])
                    return false; // if already colored with same color, can't be bipartite!
            }
        }
    }

    return true;
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