// https://codeforces.com/problemset/problem/1209/D
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k;
    cin>>n>>k;

    for(int i=0; i<k; i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n, 0);
    function<void(int)>dfs_helper;
    dfs_helper = [&](int src){
        visited[src]=true;
        for(int child: adj[src]){
            if(!visited[child]){
                dfs_helper(child);
            }
        }
    };

    int ct=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ct++;
            dfs_helper(i);
        }
    }
    
    cout<<k-(n-ct)<<endl;
    return 0;
}