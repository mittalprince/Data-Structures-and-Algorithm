// Kamil and Making a Stream
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100005

/*
Logic: We normal use DFS for each node in top down manner, menas we travere all child of a node except upper level nodes

and for each node we maintain a map to store the freq of val that we obtain from gcd of anccestor node val and arr[node] val
and add into ans (freq of no*no).

*/
ll n;
vector<ll> adj[MAX];
ll arr[MAX];
ll ans=0;
unordered_map<ll, ll>node_path[MAX];

ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

void DFS(ll src, ll parent){

    node_path[src][arr[src]]++;

    for(auto it: node_path[parent]){
        node_path[src][gcd(arr[src],it.first)] += it.second;
    }

    for(auto it: node_path[src]){
        ans = (ans + it.first*it.second)%MOD;
    }

    for(auto child: adj[src]){
        if(child != parent){
            DFS(child, src);
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    ip(arr, n);

    for(ll i=0; i<n-1; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 0);

    cout<<ans<<endl;
    return 0;
}