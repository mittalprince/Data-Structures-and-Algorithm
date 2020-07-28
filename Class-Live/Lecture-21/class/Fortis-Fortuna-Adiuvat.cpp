#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e10
#define INF 1e16
#define MOD 1000000007
#define MAX 100005

ll n,m,x,q;
ll NodeSeHotelKaDistance[MAX], HotelSeNodeKaDistance[MAX];
vector<pair<ll, ll> >adj[MAX], transpose_adj[MAX];

void HotelSeNodeKaBFS(){
    
    vector<bool>visited(MAX, false);
    for(ll i=0; i<=n; i++){
        HotelSeNodeKaDistance[i]=INF;
    }

    HotelSeNodeKaDistance[x]=0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >q;
    q.push({0, x});

    while(!q.empty()){
        pair<ll, ll> top = q.top();
        q.pop();

        ll parent = top.second;
        ll parent_dist = top.first;

        if(visited[parent])continue;
        visited[parent]=true;

        for(pair<ll, ll> child: adj[parent]){
            if(HotelSeNodeKaDistance[child.first]>parent_dist+child.second){
                HotelSeNodeKaDistance[child.first] = parent_dist+child.second;
                q.push({HotelSeNodeKaDistance[child.first], child.first});
            }
        }
    }
}

void NodeSeHotelKaBFS(){
    vector<bool> visited(MAX, false);
    for(ll i=0; i<=n; i++){
        NodeSeHotelKaDistance[i]=INF;
    }

    NodeSeHotelKaDistance[x]=0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >q;
    q.push({0, x});

    while(!q.empty()){
        pair<ll, ll> top = q.top();
        q.pop();

        ll parent = top.second;
        ll parent_dist = top.first;

        if(visited[parent])continue;
        visited[parent]=true;

        for(pair<ll, ll> child: transpose_adj[parent]){
            if(NodeSeHotelKaDistance[child.first]>parent_dist+child.second){
                NodeSeHotelKaDistance[child.first] = parent_dist+child.second;
                q.push({NodeSeHotelKaDistance[child.first], child.first});
            }
        }
    }
}

void solve(int &tc){
    cin>>n>>m>>x>>q;
    x--;

    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back({v,w});
        transpose_adj[v].push_back({u,w});
    }

    HotelSeNodeKaBFS();
    NodeSeHotelKaBFS();

    cout<<"Case "<<tc++<<":"<<endl;
    for(ll i=0; i<q; i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        ll ans = NodeSeHotelKaDistance[u]+HotelSeNodeKaDistance[v];
        if(ans >= INF){
            cout<<"Be seeing ya, John"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }


    for(ll i=0; i<=n; i++){
        adj[i].clear();
        transpose_adj[i].clear();
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
        solve(tc);
    }
    return 0;
}