// https://www.codechef.com/ENAU2020/problems/ECAUG207
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
#define MAX 100005

vector<ll>adj[MAX];

void solve(){
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        // cout<<u<<" "<<v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ct(n+1, 0);
    vector<bool>visited(n+1, false);

    int ans=inf;
    int ans_node=-1;

    function<ll(int)>dfs_helper;
    dfs_helper = [&](int src)->int{
        visited[src]=true;
        ct[src]=1;

        int sum=0, mx=0;
        for(int child: adj[src]){
            if(!visited[child]){
                ct[src] += dfs_helper(child);
                sum += ct[child];
                mx = max(mx, ct[child]);
            }
        }
        int rem = n-sum-1;
        if(ans > max(rem, mx)){
            ans = max(rem, mx);
            ans_node = src;
        }
        if(ans == max(rem, mx)){
            ans_node = min(ans_node, src);
        }
        return ct[src];
    };

    dfs_helper(1);
    cout<<ans_node<<" "<<ans<<endl;

    for(int i=0; i<=n; i++)adj[i].clear();
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