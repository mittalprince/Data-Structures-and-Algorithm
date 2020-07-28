#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<algorithm>
#include<functional>
#include<climits>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// Implement weighted graph and BFS< DFS and SSSP using adjancey list

template <typename T>
class Graph{
    int V,E;
    map<T, list<pair<T, int> > >adj;

    public:
    Graph(int v, int e):V(v),E(e){}

    void addEdge(T u, T v, int wt, bool bidir=true){
        adj[u].push_back({v,wt});
        if(bidir){
            adj[v].push_back({u,wt});
        }
    }

    void printGraph(){
        for(auto node: adj){
            cout<<"Src "<<node.first<<" ";
            for(auto child: adj[node.first]){
                cout<<", Child -> "<<child.first;
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

            for(auto child: adj[src]){
                if(!visited[child.first]) dfs_helper(child.first);
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

    // BFS unweighted graph ke liye hota hai and Dijisktra wieghted ke liye
    // as in normal BFS once we updated the dist we never update it again, means once node visited we dont
    // viste it again and hene can not update dist again, where as in dijisktra we use condition that if child dist > then update
    // it every time for every chiid of node.
    
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

            for(auto child: adj[front]){
                if(!visited[child.first]){
                    q.push(child.first);
                    visited[child.first]=true;
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
        set<pair<int, T> >q;

        for(auto node: adj){
            dist[node.first]=INT_MAX;
        }

        dist[src]=0;
        parent[src]=src;

        
        q.insert({0,src});

        while(!q.empty()){
            pair<int, T> p = *q.begin();
            q.erase(q.begin());

            int parent_dist = p.first;
            T node = p.second;

            for(auto child: adj[node]){
                if(dist[child.first]>parent_dist+child.second){
                    parent[child.first]=node;
                    auto f = q.find({dist[child.first], child.first});
                    if(f!=q.end()){
                        q.erase(f);
                    }
                    dist[child.first] = parent_dist+child.second;
                    q.insert({dist[child.first], child.first});
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
        int u,v,wt;
        cin>>u>>v>>wt;
        g.addEdge(u, v, wt);
    }

    g.DFS();
    cout<<endl;

    int src, dest;
    cin>>src;
    g.BFS(src);
    cout<<endl;

    cin>>src>>dest;
    cout<<g.SSSP(src, dest)<<endl;;
    return 0;
}