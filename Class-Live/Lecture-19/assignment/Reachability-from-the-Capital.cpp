// Reachability from the Capital
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<list>
#include<queue>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 1000005

template<typename T>
class Graph{
    int V;
    unordered_map<T, list<T> >adj;
    vector<pair<int, ll> > bad_vertex_track;
    vector<bool> visited;

    public:

    Graph(int v):V(v){
        visited = vector<bool>(MAX, 0);
    }
    
    void addEdge(T u, T v, bool birdir=true){
        adj[u].push_back(v);
        if(birdir){
            adj[v].push_back(u);
        }
    }

    void DFS(T src){
        visited[src]=true;

        for(T child: adj[src]){
            if(!visited[child]){
                DFS(child);
            }
        }
    }

    int MinExtraEdgesReq(){
        vector<bool>bad_vertex(MAX,0);

        int ct=0; 

        function<void(T)>min_extra_edges_req_helper;
        min_extra_edges_req_helper = [&](T src){
            bad_vertex[src]=true;
            ct++;

            for(T child: adj[src]){
                
                if(!visited[child] && !bad_vertex[child]){
                    min_extra_edges_req_helper(child);
                }
            }
        };

        
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                ct=0;
                min_extra_edges_req_helper(i);
                bad_vertex.assign(V+1, 0);
                bad_vertex_track.push_back({ct, i});
            }
        }

        sort(bad_vertex_track.begin(), bad_vertex_track.end());
        reverse(bad_vertex_track.begin(), bad_vertex_track.end());

        ll ans=0;

        for(pair<int, T> it: bad_vertex_track){
            if(!visited[it.second]){// if node is bad vertex
                ans++; // increment ans as we add an edge from sorurce to this node directly
                DFS(it.second); // and marked all bad vertex that can be reached through this as visited
            }
        }

        return ans;
    }
};

void solve(){
    int n,m;
    int src_vertex;

    cin>>n>>m>>src_vertex;

    Graph<int> g(n);
    // set<pair<ll ,ll> >s;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // if(s.find({u,v}) == s.end()){
            g.addEdge(u, v, false);
            // s.insert({u,v});
        // }
    }

    g.DFS(src_vertex);

    cout<<g.MinExtraEdgesReq()<<endl;
}

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}