#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 200005

/*
Logic: Used BFS
Here we try to gen the BFS seq in order which is given. 
For this we maintain a map which tell the ith node given BFS in on which idx, means
Consider 1 3 2 4 (given bfs)
So maping will be like this 
1 index -> 0 ( 1 node of graph is on 0 index)
2 index -> 2 (2 node og graph is on 2 index)
3 index -> 1
4 index -> 3  

Now using this mapping we gen the BFS.
For each list of nodes we sort the list and put nodes first which appear phela in BFS.
means used above maping to sort, whose given_bfs_idx ki val choti hogi voh list mein phrla aeyga
*/

ll n;
ll given_bfs_idx[MAX]={0};
vector<ll>given_bfs;

class Graph{
    unordered_map<ll, vector<ll> >adj;

    public:

    void addEdge(ll u, ll v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool BFS(ll src){
        unordered_map<ll, bool>visited;

        queue<ll>q;
        q.push(src);
        visited[src]=true;
        vector<ll>ans;

        while(!q.empty()){
            ll front = q.front();
            q.pop();

            ans.push_back(front);

            sort(adj[front].begin(), adj[front].end(), [&](const ll &a, const ll &b){
                return given_bfs_idx[a]<given_bfs_idx[b];
            });

            for(ll child: adj[front]){
                if(!visited[child]){
                    visited[child]=true;
                    q.push(child);
                }
            }
        }
        return (ans == given_bfs);
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    Graph g;

    cin>>n;
    for(ll i=1; i<n; i++){
        ll u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    
    for(ll i=0; i<n; i++){
        ll x; cin>>x;
        given_bfs.push_back(x);
    }

    for(ll i=0; i<n; i++){
        given_bfs_idx[given_bfs[i]]=i;
    }

    if(g.BFS(1)){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    return 0;
    
}