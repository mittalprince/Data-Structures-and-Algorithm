#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 10005

ll n,m;
vector<ll>adj[MAX];
vector<bool>visited, ap;
vector<ll>parent, discovery, low;

void solve(){

    parent = vector<ll>(n + 1, -1);
    visited = vector<bool>(n + 1, false);
    discovery = vector<ll>(n + 1, 0);
    low = vector<ll>(n + 1, 0); // check is there is an back edge(if the subtree rooted with v has a connection to
    // one of the ancestors of u).

    ap = vector<bool>(n + 1, false);
    ll time=0;

    function<void(ll)>dfs_helper;
    dfs_helper = [&](ll src){
        visited[src]=true;
        discovery[src]=low[src]=++time;

        ll children=0;
        for(ll child: adj[src]){
            if(!visited[child]){
                children++;
                parent[child]=src;
                dfs_helper(child);
                low[src] = min(low[child], low[src]);
                
                // if src is the root of dfs tree and it has atleast 2 child
                if(parent[src] == -1 and children>1){
                    ap[src]=true;
                }
                // if not root but low value of one of its child is more
                // than discovery value of u.
                if(parent[src] != -1 and low[child]>=discovery[src]){
                    ap[src]=true;
                }
            }
            else if(child != parent[src]){
                low[src] = min(low[src], discovery[child]);
            }
        }
    };

    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            dfs_helper(i);
        }
    }

    ll ans=0;
    for(ll i=0; i<=n; i++){
        ans += ap[i];
    }

    cout<<(1<<4)<<endl;
    cout<<ans<<endl;
    // for(ll i=1; i<=n; i++){
    //     if(ap[i])cout<<i<<" ";
    // }
    // cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    while(n and m){
        for(ll i=0; i<m; i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve();
    
        for(ll i=0; i<=n; i++){
            adj[i].clear();
        }

        cin>>n>>m;
    }
    return 0;
}