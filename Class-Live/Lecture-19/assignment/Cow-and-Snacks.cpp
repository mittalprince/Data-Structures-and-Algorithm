// Cow and Snacks
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<list>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll n,k;

template<typename T>
class Graph{
    ll V;
    unordered_map<T, list<T> >adj;

    public:
    Graph(ll v):V(v){}

    void addEdge(T u, T v, bool bidir=true){
        adj[u].push_back(v);
        if(bidir) adj[v].push_back(u);
    }

    ll DFS(){
        unordered_map<T, bool>visited;
        ll connect_components=0;

        function<void(T)>dfs_helper;
        dfs_helper = [&](T src){
            visited[src]=true;

            for(T child: adj[src]){
                if(!visited[child]){
                    dfs_helper(child);
                }
            }
        };

        for(ll i=1; i<=V; i++){
            if(!visited[i]){
                connect_components++;
                dfs_helper(i);
            }
        }

        // cout<<connect_components<<endl;
        return k-(n-connect_components);
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>k;
    Graph<ll> g(n);

    for(int i=0; i<k; i++){
        ll u,v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<g.DFS()<<endl;
    return 0;
}
/*
use the nodes ans dishes and edges as guests, we create disjoint components
a single component of size c is at max capable of feeding c-1 guests
as the 1st guest will eat 2 dishes rest eat one
use dsu to create disjoint components
total satisfied guests = comp_size - 1 , for each component
hence, comp_size1 -1 + compo_size2 - 1... comp_sizen -1
(comp_size1 to comp_sizen) == n and -1 occurs n times
hence, satisfied guest-> n - c
unsatisfied guests = k- (n-c)
*/