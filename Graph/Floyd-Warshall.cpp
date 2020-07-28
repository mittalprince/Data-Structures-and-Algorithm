// Floyd Warshall
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 1005

/*
Used to find shortest dist from any given src to any given dest.
find shortest distances between every pair of vertices in a given edge weighted directed Graph
*/
vector<vector<pair<ll, ll> > >adj(MAX);
ll n,m;

void FloydWarshall(){

    vector<vector<ll> >dist(MAX, vector<ll>(MAX, INT_MAX));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<adj[i].size(); j++){
            ll u=i;
            ll v=adj[i][j].first;
            ll w=adj[i][j].second;

            dist[u][v]=w;
        }
        dist[i][i]=0;
    }

    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(ll i=0; i<n; i++){
        if(dist[i][i]<0){
            cout<<"Negative Cycle present\n";
            return;
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(dist[i][j] == INT_MAX){
                cout<<"INF ";
            }
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    FloydWarshall();
    return 0;
}

/*
4 5
1 2 1
1 4 5
2 3 3
2 4 1
4 3 1

0 1 3 2 
1 0 2 1 
3 2 0 1 
2 1 1 0 
*/