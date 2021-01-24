//https://www.hackerearth.com/problem/algorithm/strategic-warehouse-placements/?layout=old
#include<iostream>
#include<vector>
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

vector<int>adj[10005];
vector<int>deg(10005,0);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;deg[v]++;
    }

    int ans=0;
    while(true){
        int idx, deg_mx=-1;
        for(int i=1; i<=n; i++){
            if(deg[i]>deg_mx){
                deg_mx = deg[i];
                idx=i;
            }
        }
        if(deg_mx==-1)break;
        deg[idx]=-1;
        for(int i: adj[idx]){
            deg[i]=-1;
            for(int j: adj[i]){
                deg[j]--;
            }
        }
        ans++;
    }
    cout<<min(ans,3)<<endl;
    return 0;
}