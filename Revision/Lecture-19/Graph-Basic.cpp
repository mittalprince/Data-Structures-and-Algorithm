#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<map>
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

template<typename T>
class Graph{
    map<T, list<T> >adj;
    int V,E;

    public:
    Graph(int v, int e):V(v),E(e){}

    void addEdge(T u, T v, bool bidir=true){
        adj[u].push_back(v);
        if(bidir) adj[v].push_back(u);
    }

    void printGraph(){
        for(auto node: adj){
            cout<<"Src "<<node.first<<" ";
            for(T child: adj[node]){
                cout<<", Child -> "<<child;
            }
            cout<<endl;
        }
    }

    void DFS(){
        map<T, bool>visited;
        vector<vector<T> >ans;
        vector<T>t;

        int components=0;

        function<void(T)>dfs_helper;
        dfs_helper = [&](T src){
            visited[src]=true;
            t.push_back(src);

            for(T child: adj[src]){
                if(!visited[child]){
                    dfs_helper(child);
                }
            }
        };

        for(auto node: adj){
            if(!visited[node.first]){
                components++;
                t.clear();
                dfs_helper(node);
                ans.push_back(t);
            }
        }

        cout<<"Total Connected Components is "<<components<<endl;
        cout<<"DFS of given graph\n";
        for(vector<T> a: ans){
            for(T i: a){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void BFS(T src){
        map<T, bool>visited;
        queue<T>q;
        q.push(src);
        visited[src]=true;

        vector<T>ans;

        while(!q.empty()){
            T top = q.front();
            q.pop();
            ans.push_back(top);

            for(T child: adj[top]){
                if(!visited[child]){
                    visited[child]=true;
                    q.push(child);
                }
            }
        }

        cout<<"BFS of given graph "<<endl;
        for(T i: ans){
            cout<<i<<" "; 
        }
        cout<<endl;
    }

    int SSSP(T src, T dest){
        map<T,T>parent;
        map<T, int>dist;

        for(auto node:adj){
            dist[node.first]=inf;
        }

        parent[src]=src;
        dist[src]=0;

        queue<T>q;
        q.push(src);

        while(!q.empty()){
            T top=q.front();
            q.pop();

            int parent_dist = dist[top];
            for(int child: adj[top]){
                if(dist[child] == inf){
                    dist[child] = parent_dist+1;
                    parent[child]=top;
                    q.push(child);
                }
            }
        }

        for(auto node: dist){
            cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
        }

        T t=dest;
        while(t != src){
            cout<<t<<"<--";
            t = parent[t];
        }
        cout<<src<<endl;

        return dist[dest];
    }
};

void helper(){
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];

    function<void(int,int)>addEdge;
    addEdge = [&](int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    function<void(int)>print;
    print = [&](int vertices){
        for(int i=0; i<vertices; i++){
            cout<<"Adjanceny List of node "<<i<<endl;
            for(int j: adj[i]){
                cout<<"Edge "<<j<<"\n";
            }
        }
    };

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    print(v);
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