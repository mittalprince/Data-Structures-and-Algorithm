#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// Implement DFS using both adjancey list and matrix 

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

    void DFS_Iterative(){

        map<T, bool>visited;
        vector<vector<T> >ans;
        vector<T>t;

        int connected_components = 0;

        function<void(T)>dfs_helper;
        dfs_helper = [&](T src){
            stack<T> s;
            s.push(src);
            visited[src]=true;

            while(!s.empty()){
                T top = s.top();
                s.pop();

                t.push_back(top);

                for(T child: adj[top]){
                    if(!visited[child]){
                        s.push(child);
                        visited[child]=true;
                    }
                }
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
};

class graph{
    int V,E;
    vector<vector<int> >adj;

    public:
    graph(int v, int e){
        V = v;
        E = e;
        adj = vector<vector<int> >(v+1, vector<int>(v+1, 0));
    }

    void addEdge(int u, int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }

    void DFS(){
        map<int, bool> visited;
        vector<vector<int> >ans;
        vector<int>t;

        int connected_components=0;

        function<void(int)>dfs_helper;
        dfs_helper = [&](int src){
            t.push_back(src);
            visited[src]=true;

            for(int i=0; i<adj[src].size(); i++){
                if(adj[src][i]==1 && !visited[i]){
                    dfs_helper(i);
                }
            }
        };

        for(int i=0; i<V; i++){
            if(!visited[i]){
                connected_components++;
                t.clear();
                dfs_helper(i);
                ans.push_back(t);
            }
        }

        cout<<"Total Connected Components is "<<connected_components<<endl;
        cout<<"DFS of given graph\n";
        for(vector<int> a: ans){
            for(int i: a){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

void adjMatrix(){
    int v,e;
    cin>>v>>e;

    graph g(v, e);
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    g.DFS();
}

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

    g.DFS();
    cout<<endl;
    g.DFS_Iterative();

    adjMatrix();
    return 0;
}