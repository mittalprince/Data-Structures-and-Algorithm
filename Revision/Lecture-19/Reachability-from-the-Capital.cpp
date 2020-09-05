// https://codeforces.com/contest/999/problem/E
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
#define MAX 5005

vector<ll>adj[MAX];
vector<bool>visited, bad_vertex;
int ct=0;

void DFS(int src){
    visited[src]=true;

    for(int child: adj[src]){
        if(!visited[child]){
            DFS(child);
        }
    }
}

void DFS2(int src){
    bad_vertex[src]=true;
    ct++;

    for(int child: adj[src]){
        if(!visited[child] and !bad_vertex[child]){
            DFS2(child);
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m,src;
    cin>>n>>m>>src;

    visited = vector<bool>(n+1, 0);
    bad_vertex = vector<bool>(n+1, 0);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    DFS(src);
    
    vector<pair<int, int> >bad_vertex_track;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            ct=0;
            DFS2(i);
            bad_vertex.assign(n+1, 0);
            bad_vertex_track.push_back({ct, i});
        }
    }

    sort(bad_vertex_track.rbegin(), bad_vertex_track.rend());
    int ans=0;

    for(pair<int, int> i: bad_vertex_track){
        if(!visited[i.second]){
            ans++;
            DFS(i.second);
        }
    }

    cout<<ans<<endl;
    return 0;
}