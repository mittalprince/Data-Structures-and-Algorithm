#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll n,p;

template <typename T>
class Graph{
    unordered_map<T, list<T> >adj;

    public:

    void addEdge(T u, T v, bool birdir=true){
        adj[u].push_back(v);
        if(birdir){
            adj[v].push_back(u);
        }
    }

    ll totalPossilbePairs(){
        unordered_map<T, bool>visited;

        ll total_pair = n*(n-1)/2;
        ll ans=0;

        function<void(T)>dfs_helper;
        dfs_helper = [&](T src){
            visited[src]=true;
            ans++;

            for(T child: adj[src]){
                if(!visited[child]){
                    dfs_helper(child);
                }
            }
        };

        dfs_helper(0);
        total_pair -= (ans*(ans-1)/2);

        for(auto node: adj){
            if(!visited[node.first]){
                ans=0;
                dfs_helper(node.first);
                total_pair -= (ans*(ans-1)/2);
            }
        }

        return total_pair;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    Graph<ll>g;

    cin>>n>>p;

    for(int i=0; i<p; i++){
        ll u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<g.totalPossilbePairs()<<endl;
    return 0;
}