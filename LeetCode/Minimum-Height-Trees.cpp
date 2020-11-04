//https://leetcode.com/problems/minimum-height-trees/
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

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==0)
        return {};
    if(n==1)
        return {0};
    vector<int>res;
    vector<int>degrees(n,0);
    vector<vector<int>>adj(n);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
        adj[edges[i][1]].push_back(edges[i][0]);
        degrees[edges[i][1]]++;//updating how many edges each node has
        degrees[edges[i][0]]++;
    }
    queue<int>queue;
    for(int i=0;i<n;i++)
    {
        if(degrees[i]==1)//adding all the leave nodes
            queue.push(i);
    }
    while(!queue.empty())
    {
        res.clear();// clear vector before we start traversing level by level.
        int size=queue.size();
        for(int i=0;i<size;i++)
        {
            int cur=queue.front();
            queue.pop();
            res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
            for(auto &neighbor:adj[cur])
            {
                degrees[neighbor]--;//removing current leave nodes
                if(degrees[neighbor]==1)//adding current leave nodes
                    queue.push(neighbor);
            }
        }
    }
    return res;
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