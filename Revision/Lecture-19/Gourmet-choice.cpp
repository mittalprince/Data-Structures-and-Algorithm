// https://codeforces.com/problemset/problem/1131/D
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
#define MAX 2005

vector<pair<ll, ll> >edges;
vector<ll>adj[MAX];
bool isCyclic = false;
bool visited[MAX]={0}, isNodeInStack[MAX]={0};
ll depth[MAX]={0};

class DSU{
    vector<ll>parent, rank;

    public:
    DSU(ll v){
        parent.resize(v), rank.resize(v);
        for(int i=0; i<v; i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    ll find(ll a){
        if(a == parent[a])return a;
        return parent[a]=find(parent[a]);
    }

    void merge(ll a, ll b){
        a = find(a);
        b = find(b);

        if(a!=b){
            if(rank[a]<rank[b])swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
        }
    }
};

void findDepth(ll src){
    if(visited[src])return;
    if(isCyclic)return;

    if(isNodeInStack[src]){
        isCyclic=true;
        return;
    }
    isNodeInStack[src]=true;

    ll d=0;
    for(ll child: adj[src]){
        findDepth(child);
        d = max(d, depth[child]);
    }

    isNodeInStack[src]=false;
    visited[src]=true;
    depth[src]=d+1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;

    DSU g(n+m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;

            if(ch=='='){
                g.merge(i, n+j);
            }
            else if(ch=='>'){
                edges.push_back({i, n+j});
            }
            else{
                edges.push_back({n+j, i});
            }
        }
    }
    
    for(pair<ll, ll>i: edges){
        adj[g.find(i.first)].push_back(g.find(i.second));
    }

    for(ll i=0; i<n+m; i++){
        if(!visited[i]){
            findDepth(g.find(i));
        }
    }

    if(isCyclic){
        cout<<"No\n";
        return 0;
    }
    
    cout<<"Yes\n";
    for(int i=0; i<n; i++){
        cout<<depth[g.find(i)]<<" ";
    }
    cout<<endl;
    for(int i=0; i<m; i++){
        cout<<depth[g.find(n+i)]<<" ";
    }
    cout<<endl;
    return 0;
}