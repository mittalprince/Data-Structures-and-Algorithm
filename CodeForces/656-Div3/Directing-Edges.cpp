// https://codeforces.com/contest/1385/problem/E
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<functional>
#include<stack>
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
#define MAX 200005

/*
The idea is to use Topological Sorting. Following are two steps used in the algorithm.

1) Consider the subgraph with directed edges only and find topological sorting of the subgraph.
Use above topological sorting to assign directions to undirected edges. For every undirected edge (u, v), 
assign it direction from u to v if u comes before v in topological sorting, else assign it direction from v to u.
*/

class Graph { 
    int V;      
    list<int> *adj; 
public: 

    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }    
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    vector<int> topologicalSort(){
        stack<int>s;
        vector<int>ans;

        vector<bool>visited(V, false);

        function<void(int)>helper;
        helper = [&](int src){
            visited[src]=true;

            for(int child: adj[src]){
                if(!visited[child]){
                    helper(child);
                }
            }
            s.push(src);
        };

        for(int i=0; i<V; i++){
            if(!visited[i]){
                helper(i);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }

    bool isCyclic(){
        vector<bool>visited(V, false), inStack(V, false);

        function<bool(int)>isCyclePresent;
        isCyclePresent = [&](int src)->bool{
            if(!visited[src]){
                visited[src]=true;
                inStack[src]=true;

                for(int child: adj[src]){
                    if(inStack[child] or (!visited[child] and isCyclePresent(child))){
                        return true;
                    }
                }
            }
            inStack[src]=false;
            return false;
        };

        for(int i=0; i<V; i++){
            if(isCyclePresent(i)){
                return true;
            }
        }
        return false;
    }
}; 

void solve(){

    int n,m;
    cin>>n>>m;

    Graph g(n+1);

    vector<pair<int, int>> directed_edges, undirected_edges;
    
    for(int i=0; i<m; i++){
        int type,u,v;
        cin>>type>>u>>v;
        if(type){
            g.addEdge(u,v);
            directed_edges.push_back({u,v});
        }
        else undirected_edges.push_back({u,v});
    }

    if(g.isCyclic()){
        cout<<"NO\n";
        return;
    }

    vector<int>ts = g.topologicalSort();
    map<int, int>pos;
    
    for(int i=0; i<ts.size(); i++){
        pos[ts[i]]=i;
    }

    cout<<"YES\n";

    for(int i=0; i<undirected_edges.size(); i++){
        if(pos[undirected_edges[i].first]<pos[undirected_edges[i].second]){
            cout<<undirected_edges[i].first<<" "<<undirected_edges[i].second<<endl;
        }
        else{
            cout<<undirected_edges[i].second<<" "<<undirected_edges[i].first<<endl;
        }
    }
    for(auto it: directed_edges){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){

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