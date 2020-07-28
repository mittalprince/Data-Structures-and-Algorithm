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

    void addEdge(T u, T v, bool bidir=false){
        adj[u].push_back(v);
        inDeg[v]++;
        if(bidir){
            adj[v].push_back(u);
            inDeg[u]++;
        }
    }

    bool isCyclic_DFS(){
        unordered_map<T, bool>visited, instack;

        function<bool(T)>dfs_helper;
        dfs_helper = [&](T src)->bool{
            visited[src]=true;
            instack[src]=true;

            for(T child: adj[src]){
                if(instack[child] or (!visited[child] and dfs_helper(child))){
                    return true;
                }
            }
            instack[src]=false;
            return false;
        };

        for(auto node: adj){
            if(!visited[node.first]){
                bool cycle_present = dfs_helper(node.first);
                if(cycle_present)return true;
            }
        }

        return false;
    }

    bool isCyclic_BFS(){
        queue<T>q;

        for(auto node: adj){
            if(inDeg[node.first]==0){
                q.push(node.first);
            }
        }
        int ct=0;

        while(!q.empty()){
            T front = q.front();
            q.pop();

            for(T child: adj[front]){
                inDeg[child]--;
                if(inDeg[child]==0){
                    q.push(child);
                }
            }
            ct++;
        }

        return !(ct == adj.size());
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n;
	cin>>n;
	Graph<string> g;
	for(ll i = 0 ; i  < n ; i ++){
		string x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	cout<<(g.isCyclic_DFS())<<endl;
    cout<<(g.isCyclic_BFS())<<endl;
    return 0;
}