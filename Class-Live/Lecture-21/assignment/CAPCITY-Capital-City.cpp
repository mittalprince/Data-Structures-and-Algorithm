#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<climits>
#include<iterator>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 100005

ll n,m;
vector<ll>adj[MAX], transpose_adj[MAX];
bool visited[MAX]={false};
vector<ll>order;
set<ll>temp, ans;

void DFS(ll src){
    visited[src]=true;

    for(ll child: adj[src]){
        if(!visited[child]){
            DFS(child);
        }
    }
    order.push_back(src);
}

void DFST(ll src){
    visited[src]=true;
    temp.insert(src);

    for(ll child: transpose_adj[src]){
        if(!visited[child]){
            DFST(child);
        }
    }
}

void SCC(){
    memset(visited, false, sizeof(visited));
    
    for(ll i=1; i<=n; i++){
        if(!visited[i])
            DFS(i);
    }
    
    memset(visited, false, sizeof(visited));
    for(ll i=n; i>=1; i--){
        if(!visited[order[i]]){
            DFST(order[i]);
            if(temp.size()>ans.size())ans=temp;
            temp.clear();
        }
    }

    cout<<ans.size()<<endl;
    for(ll i: ans){
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
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        transpose_adj[v].push_back(u);
    }

    SCC();
    return 0;
}