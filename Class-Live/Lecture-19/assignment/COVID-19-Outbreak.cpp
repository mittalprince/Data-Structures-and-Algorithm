#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 1000005

vector<pair<ll, ll> >adj[MAX];
ll arr[MAX];

ll DFS(ll src, ll parent){
    ll ans = arr[src];

    for(pair<ll, ll> child: adj[src]){
        if(child.first != parent){
            ll t = DFS(child.first, src);
            ans += min(t, child.second);
        }
    }
    return ans;
}   

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    int n,z;
    cin>>n>>z;

    for(int i=0; i<n-1; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u,w});
    }

    ip(arr, n);

    cout<<DFS(z-1, -1)<<endl;
    return 0;
}