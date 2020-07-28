// https://codeforces.com/contest/20/problem/C
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<climits>
#include<queue>
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
#define MAX 100005

vector<vector<pair<ll, ll> > >adj(MAX);
vector<unordered_map<ll, ll> >t(MAX);
int n,m;

void BFS(){
    set<pair<ll, ll> >q;
    unordered_map<ll, ll>Parent, dist;

    for(int i=1; i<=n; i++){
        dist[i]=LLONG_MAX;
    }

    dist[1]=0;
    Parent[1]=1;
    q.insert({0, 1});
    bool flag=false;

    while(!q.empty()){
        pair<ll, ll>top = *q.begin();
        q.erase(q.begin());

        ll parent = top.second;
        ll parent_dist = top.first;

        if(parent == n){
            flag=true;
            break;
        }
        for(auto child: adj[parent]){
            if(dist[child.first] > child.second+parent_dist){
                auto f = q.find({dist[child.first], child.first});
                if(f != q.end()){
                    q.erase(f);
                }
                Parent[child.first]=parent;
                dist[child.first] = parent_dist+child.second;
                q.insert({dist[child.first], child.first});
            }
        }
    }
    
    if(!flag){
        cout<<"-1\n";
        return;
    }
    int t=n;
    vector<int>ans;
    while(t != 1){
        ans.push_back(t);
        t = Parent[t];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        if(u != v){
            if(t[u].find(v) == t[u].end()){
                t[u][v]=w;
                t[v][u]=w;
            }
            else{
                t[u][v] = min(w, t[u][v]);
                t[v][u] = min(w, t[v][u]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(auto it=t[i].begin(); it != t[i].end(); it++){
            adj[i].push_back({it->first, it->second});
            adj[it->first].push_back({i, it->second});
        }
    }
    BFS();

    return 0;
}