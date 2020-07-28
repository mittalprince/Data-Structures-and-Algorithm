#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>
#include <set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// SSSP using adjancey matrix on both weighted and unweighted

class graph{
    int V,E;
    vector<vector<int> >adj;

    public:

    graph(int v){
        this->V = v;
        adj = vector<vector<int> >(V+1, vector<int>(V+1, 0));
    }

    void addEdge(int u, int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }

    int SSSP(int src, int dest){
        map<int, int> parent, dist;

        for(int i=0; i<V; i++){
            dist[i]=INT_MAX;
        }
        parent[src]=src;
        dist[src]=0;

        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            int parent_dist = dist[front];
            for(int i=0; i<adj[front].size(); i++){
                if(adj[front][i]==1 && dist[i] == INT_MAX){
                    dist[i] = parent_dist+1;
                    parent[i]=front;
                    q.push(i);
                }
            }
        }

        for(auto node: dist){
            cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
        }

        int temp = dest;

        while(temp != src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        return dist[dest];
    }
};

void unweighted(){
    int v,e;
    cin>>v>>e;
    graph g(v);

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int src, dest;
    cin>>src>>dest;

    cout<<g.SSSP(src, dest)<<endl;
}

class Graph{
    int V;
    vector<vector<int> >adj;

    public:
    Graph(int v){
        this->V = v;
        adj = vector<vector<int> >(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w){
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int SSSP(int src, int dest){
        map<int, int>dist, parent;
        set<pair<int, int> >q;

        for(int i=0; i<V; i++){
            dist[i] = INT_MAX;
        }

        dist[src]=0;
        parent[src]=src;

        q.insert({0, src});

        while(!q.empty()){
            pair<int, int> front = *q.begin();
            q.erase(q.begin());

            int parent_dist = front.first;
            int node = front.second;

            for(int i=0; i<adj[node].size(); i++){
                if(adj[node][i] && dist[i] > parent_dist+adj[node][i]){
                    parent[i]=node;
                    auto f = q.find({dist[i], i});
                    if(f != q.end()){
                        q.erase(f);
                    }
                    dist[i] = parent_dist+adj[node][i];
                    q.insert({dist[i], i});
                }
            }
        }

        for(auto node: dist){
            cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
        }

        int temp = dest;

        while(temp != src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        return dist[dest];
    }
};

void weighted(){
    int v,e;
    cin>>v>>e;
    Graph g(v);

    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    int src, dest;
    cin>>src>>dest;

    cout<<g.SSSP(src, dest)<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // unweighted();
    weighted();

    return 0;
}