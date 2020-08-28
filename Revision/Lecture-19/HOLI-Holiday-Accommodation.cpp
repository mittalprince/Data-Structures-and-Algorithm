// https://www.spoj.com/problems/HOLI/
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
vector<pair<ll, ll> >adj[MAX];

void solve(){
    ll n;
    cin>>n;
    vector<bool>visited(n, 0);
    vector<ll>cnt(n,0);

    for(int i=0; i<n-1; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ll ans=0;

    function<ll(ll)>dfs_helper;
    dfs_helper = [&](ll src)->ll{
        visited[src]=true;
        cnt[src]=1;

        for(pair<ll,ll>child: adj[src]){
            ll dx = child.second;
            if(!visited[child.first]){
                cnt[src]+=dfs_helper(child.first);
                ll right_subree_nodes = cnt[child.first];
                ll left_subtree_nodes = n-cnt[child.first];

                ans += 2*(min(right_subree_nodes, left_subtree_nodes))*dx;
            }
        }
        return cnt[src];
    };

    dfs_helper(0);
    
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

    int t, tc=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<tc++<<": ";
        solve();
    }
    return 0;
}