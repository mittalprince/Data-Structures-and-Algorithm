// https://codeforces.com/contest/1388/problem/C
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
#define MAX 100005

ll n, m, peopleInCity[MAX], hfactor[MAX], siz[MAX], happyExistinSubtreeCity[MAX];
vector<ll>adj[MAX];
vector<bool>visited;

bool ansExist;

// count total people lie in subtree of a given city
ll dfs1(ll src){
    siz[src] = peopleInCity[src];
    visited[src] = true;
    for(ll child: adj[src]){
        if(!visited[child]){
            siz[src] += dfs1(child);
        }
    }
    return siz[src];
}

/*
    size[src] = all people (happy + sad)
    hfactor[src] = happy - sad;

    so happyExistinSubtreeCity = size+hfactor/2;

    1. size+hfactor must be a multiple of 2, total happy people visit city must be an integer.

*/

ll dfs2(ll src){
    visited[src]=true;
    if((siz[src]+hfactor[src])&1){
        ansExist=false;
        return 0;
    }

    happyExistinSubtreeCity[src] = (siz[src] + hfactor[src])/2;
    if(happyExistinSubtreeCity[src]<0 or happyExistinSubtreeCity[src]>siz[src]){
        ansExist=false;
        return 0;
    }

    ll happyChild=0;
    for(ll child: adj[src]){
        if(!visited[child]){
            happyChild += dfs2(child);
        }
    }

    if(happyChild>happyExistinSubtreeCity[src]){
        ansExist=false;
        return 0;
    }
    return happyExistinSubtreeCity[src];
}

void solve(){
    ansExist = true;

    cin>>n>>m;
    for(ll i=0; i<=n; i++)adj[i].clear();

    ip(peopleInCity, n);
    ip(hfactor, n);

    for(ll i=0; i<n-1; i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited = vector<bool>(n+1, 0);
    dfs1(0);

    visited = vector<bool>(n+1, 0);
    dfs2(0);

    if(ansExist){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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