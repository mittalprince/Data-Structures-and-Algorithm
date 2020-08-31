// https://www.codechef.com/ENAU2020/problems/ECAUG206
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
#define MAX 10005

vector<int>adj[MAX];

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n, false);

    function<void(int)>dfs_helper;
    dfs_helper = [&](int src){
        visited[src]=true;
        for(int child: adj[src]){
            if(!visited[child])dfs_helper(child);
        }
    };
    int ans=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans++;
            dfs_helper(i);
        }
    }

    cout<<ans<<endl;
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