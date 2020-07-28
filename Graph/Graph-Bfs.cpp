#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// Implement BFS using both adjancey list and matrix 

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

    void BFS(int src){
        
        map<int, bool>visited;
        vector<int>ans;

        queue<int>q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(int i=0; i<V; i++){
                if(adj[front][i] == 1 && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }

        cout<<"BFS of given graph "<<endl;
        for(int i: ans){
            cout<<i<<" ";
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
    int src;
    cin>>src;
    g.BFS(src);
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

    int src;
    cin>>src;
    g.BFS(src);
    cout<<endl;
    adjMatrix();
    return 0;
}