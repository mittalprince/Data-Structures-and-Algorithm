#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<algorithm>
#include<functional>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// Implement graph using adjancey list and implment basic function print grpag, bfs, dfs, sssp on unweighted graph
template <typename T>
class Graph{
    int V,E;
    map<T, list<T> >adj;

    public:
    Graph(int v, int e):V(v),E(e){}

    void addEdge(T u, T v, bool bidir=true){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto node: adj){
            cout<<"Src "<<node.first<<" ";
            for(T child: adj[node.first]){
                cout<<", Child -> "<<child;
            }
            cout<<endl;
        }
    }

    void DFS(){
        map<T, bool>visited;
        vector<vector<T>>ans;
        vector<T>t;

        int connected_components = 0;

        function<void(T)>dfs_helper;
        dfs_helper = [&](T src){
            visited[src]=true;
            t.push_back(src);

            for(T child: adj[src]){
                if(!visited[child]) dfs_helper(child);
            }
        };

        for(auto node: adj){
            if(!visited[node.first]){
                connected_components++;
                t.clear();
                dfs_helper(node.first);
                ans.push_back(t);
            }
        }

        cout<<"Total Connected Components is "<<connected_components<<endl;
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

        queue<T>q;
        map<T, bool>visited;

        q.push(src);
        visited[src]=true;

        vector<T>ans;

        while(!q.empty()){
            T front = q.front();
            q.pop();

            ans.push_back(front);

            for(T child: adj[front]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
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
        map<T, int>dist;
        map<T, T>parent;

        for(auto node: adj){
            dist[node.first]=INT_MAX;
        }

        dist[src]=0;
        parent[src]=src;

        queue<T>q;
        q.push(src);

        while(!q.empty()){
            T front = q.front();
            q.pop();

            int parent_dist = dist[front];
            for(T child: adj[front]){
                if(dist[child] == INT_MAX){
                    dist[child] = parent_dist+1;
                    parent[child]=front;
                    q.push(child);
                }
            }
        }

        for(auto node: dist){
            cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
        }

        T temp = dest;

        while(temp != src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        return dist[dest];
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int v,e;
    cin>>v>>e;

    Graph<int>g(v, e);

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    // g.DFS();
    // cout<<endl;

    int src, dest;
    // cin>>src;
    // g.BFS(src);
    // cout<<endl;

    cin>>src>>dest;
    cout<<g.SSSP(src, dest)<<endl;;
    return 0;
}