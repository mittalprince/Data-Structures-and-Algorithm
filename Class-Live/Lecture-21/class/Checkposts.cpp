#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 100005

ll n,m;
vector<ll>order, checkPointCost;
vector<ll>Components[MAX];
vector<ll>adj[MAX], transpose_adj[MAX];
bool visited[MAX]={false};

void DFS(ll src){
    visited[src]=true;

    for(ll child: adj[src]){
        if(!visited[child]){
            DFS(child);
        }
    }
    order.push_back(src);
}

void DFST(ll src, ll comp_no){
    visited[src]=true;
    Components[comp_no].push_back(src);

    for(ll child: transpose_adj[src]){
        if(!visited[child]){
            DFST(child, comp_no);
        }
    }
}

void SCC(){
    memset(visited, false, sizeof(visited));
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }

    memset(visited, false, sizeof(visited));

    ll comp_no=0;
    for(ll i=n-1; i>=0; i--){
        if(!visited[order[i]]){
            DFST(order[i], comp_no);
            comp_no++;
        }
    }

    vector<pair<ll, ll> >temp;

    for(ll i=0; i<comp_no; i++){
        ll min_cost=inf;
        ll min_cost_count=0;
        for(ll it: Components[i]){
            if(min_cost>checkPointCost[it]){
                min_cost=checkPointCost[it];
                min_cost_count = 1;
            }
            else if(min_cost == checkPointCost[it])min_cost_count++;
        }

        if(min_cost_count){
            temp.push_back({min_cost, min_cost_count});
        }
    }

    ll total_cost=0, total_ways=1;

    for(pair<ll, ll>it: temp){
        total_cost += it.first;
        total_ways = (total_ways%MOD * it.second%MOD)%MOD;
    }
    cout<<total_cost<<" "<<total_ways<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    checkPointCost = vector<ll>(n+1);
    ip(checkPointCost, n);

    cin>>m;
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        transpose_adj[v].push_back(u);
    }
    SCC();

    return 0;
}