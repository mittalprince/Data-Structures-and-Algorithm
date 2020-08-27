#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

template <typename T>
class Graph{
    unordered_map<T, list<T> >adj;
    unordered_map<T, int>inDeg;

    public:

    void addEdge(T u, T v, bool bidir=true){
        adj[u].push_back(v);
        inDeg[v]++;
        if(bidir){
            adj[v].push_back(u);
            inDeg[u]++;
        }
    }

    void TPS_DFS(){
        unordered_map<T, bool>visited;
        list<T>ans;

        function<void(T)>dfs_helper;
        dfs_helper = [&](T src){
            visited[src]=true;

            for(T child: adj[src]){
                if(!visited[child]){
                    dfs_helper(child);
                }
            }
            ans.push_front(src);
        };

        for(auto node: adj){
            if(!visited[node.first]){
                dfs_helper(node.first);
            }
        }
        cout<<"Toplogical Sort using DFS \n";
        for(T node: ans){
            cout<<node<<" ";
        }
        cout<<endl;
    }

    // using BFS Khan Algorithm
    void TPS_BFS(){
        
        list<T>ans;
        queue<T>q;

        for(auto node: adj){
            if(inDeg[node.first]==0){
                q.push(node.first);
            }
        }

        while(!q.empty()){
            T front = q.front();
            q.pop();

            ans.push_back(front);
            for(T child: adj[front]){
                inDeg[child]--;
                if(inDeg[child]==0){
                    q.push(child);
                }
            }
        }
        cout<<"Toplogical Sort using BFS \n";
        for(T i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int e;
    cin>>e;
    Graph<int>g;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false);
    }
    
    g.TPS_DFS();
    cout<<endl;
    g.TPS_BFS();
    cout<<endl;
    return 0;
}