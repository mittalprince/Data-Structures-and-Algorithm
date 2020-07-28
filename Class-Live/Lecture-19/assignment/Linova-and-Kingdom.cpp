// Linova and Kingdom
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
We select those nodes as industry which has more child greedy.
But it gives WA in 3 case.
To handle this we count depth and subtree of each node,
then for each node that has more diff of depth-count we will selct k times.

Why? beacuse we want to max ans and if we select node which has high count and low depth as industry,
it all child will have to pay and hence ans will be max.
*/

ll n,k;

template<typename T>
class Graph{
    int V;
    unordered_map<T, list<T> >adj;
    vector<ll>depth, nodes_ct, ans;
    unordered_map<T, bool>visited;

    public:

    Graph(int v):V(v){
        depth = vector<ll>(V+1, 0);
        nodes_ct = vector<ll>(V+1, 0);
        ans = vector<ll>(V+1, 0);
    }
    
    void addEdge(T u, T v, bool birdir=true){
        adj[u].push_back(v);
        if(birdir){
            adj[v].push_back(u);
        }
    }

    ll DFS(T src){
        visited[src]=1;
        nodes_ct[src]=1;

        for(T child: adj[src]){
            if(!visited[child]){
                nodes_ct[src] += DFS(child);
            }
        }
        return nodes_ct[src];
    }

    void BFS(){
        unordered_map<T, bool>visited;
        queue<T>q;

        q.push(1);
        depth[1]=0;
        visited[1]=true;
        while(!q.empty()){
            T front = q.front();
            q.pop();

            for(T child: adj[front]){
                if(!visited[child]){
                    depth[child] = depth[front]+1;
                    visited[child]=true;
                    q.push(child);
                }
            }
        }
    }

    ll calAns(){
        BFS();
        DFS(1);

        ans[0]=INT_MIN;
        for(int i=1; i<=V; i++){
            ans[i] = depth[i]-nodes_ct[i]+1;
        }
        sort(ans.rbegin(), ans.rend());
        ll max_cost=0;
        for(ll i=0; i<k; i++){
            max_cost += ans[i];
        }

        return max_cost;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>k;
    Graph<ll> g(n);
    for(int i=1; i<n; i++){
        ll u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<g.calAns()<<endl;
    return 0;
}