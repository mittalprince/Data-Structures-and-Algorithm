#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<functional>
#include<algorithm>
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

    bool isCyclic_DFS(){
        unordered_map<T, bool>visited;

        function<bool(T, T)>dfs_helper;
        dfs_helper = [&](T src, T parent)->bool{
            visited[src]=true;

            for(T child: adj[src]){
                if(!visited[child]){
                    bool is_cycle_present = dfs_helper(child, src);
                    if(is_cycle_present) return true;
                }
                else if(child != parent){
                    return true;
                }
            }
            return false;
        };

        for(auto node: adj){
            if(!visited[node.first]){
                bool cycle_present = dfs_helper(node.first, node.first);
                if(cycle_present)return true;
            }
        }

        return false;
    }

    bool isCyclic_BFS(T src){
        unordered_map<T, bool>visited;
        unordered_map<T, T>parent;

        queue<T>q;
        visited[src]=true;
        parent[src]=src;

        q.push(src);
        
        while(!q.empty()){
            T front = q.front();
            q.pop();

            for(T child: adj[front]){
                if(visited[child] && (parent[front] != child)){
                    return true;
                }
                else if(!visited[child]){
                    parent[child]=front;
                    visited[child]=true;
                    q.push(child);
                }
            }
        }
        return false;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n;
	cin>>n;
	Graph<int> g;
	for(ll i = 0 ; i  < n ; i ++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	// cout<<(g.isCyclic_DFS())<<endl;
    cout<<(g.isCyclic_BFS(0))<<endl;
    return 0;
}