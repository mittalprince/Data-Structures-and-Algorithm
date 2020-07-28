// Two Fairs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<functional>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
Logic: we find total nodes using dfs start from a after delete node b
and simillarly we count nodes using dfs sttart from b after delete node a

ans = (n-ct1-1)*(n-ct2-1);
*/

ll n,m,a,b;

template<typename T>
class Graph{
    unordered_map<T, list<T> >adj;
    ll V;

    public:
    
    Graph(ll v):V(v){}

    void addEdge(T u, T v, bool bidir=true){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }

    ll getTotalPairs(){
        unordered_map<T, bool>visited;
        ll opt1=0, opt2=0;
        ll ct=0;

        function<void(T, T)>dfs_helper;
        dfs_helper = [&](T src, T target_node){
            assert(src<=V);
            
            visited[src]=true;
            ct++;

            for(T child: adj[src]){
                if(!visited[child] && (child != target_node)){
                    dfs_helper(child, target_node);
                }
            }
        };

        dfs_helper(a, b);
        opt1 = n-ct-1;

        visited.clear();
        ct=0;

        dfs_helper(b, a);
        opt2 = n-ct-1;

        // cout<<opt1<<" "<<opt2<<endl;
        return opt1*opt2;
    }
};

void solve(){
    cin>>n>>m>>a>>b;

    Graph<ll> g(n);

    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<g.getTotalPairs()<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}