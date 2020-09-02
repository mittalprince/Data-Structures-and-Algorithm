// https://codeforces.com/contest/1277/problem/E
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 200005

vector<ll>adj[MAX];

void solve(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    vector<bool>visited(n+1, 0);
    ll ct=0;

    function<void(ll, ll)>dfs_helper;
    dfs_helper = [&](ll src, ll target_node){
        visited[src]=true;
        ct++;

        for(ll child: adj[src]){
            if(!visited[child] and child != target_node){
                dfs_helper(child, target_node);
            }
        }
    };

    dfs_helper(a, b);
    ll opt1 = n-ct-1;

    visited = vector<bool>(n+1, 0);
    ct = 0;

    dfs_helper(b, a);
    ll opt2 = n-ct-1;

    cout<<opt1*opt2<<endl;
    for(int i=0; i<=n; i++){
        adj[i].clear();
    }
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