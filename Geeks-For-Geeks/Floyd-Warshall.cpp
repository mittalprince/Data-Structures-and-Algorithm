// Floyd Warshall
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
#define MAX 105

/*
Used to find shortest dist from any given src to any given dest.
find shortest distances between every pair of vertices in a given edge weighted directed Graph
*/
int adj[MAX][MAX];
ll n;

void FloydWarshall(){

    vector<vector<ll> >dist(n, vector<ll>(n));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>dist[i][j];
        }
    }

    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // for(ll i=0; i<n; i++){
    //     if(dist[i][i]<0){
    //         cout<<"Negative Cycle present\n";
    //         return;
    //     }
    // }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(dist[i][j] == 10000000){
                cout<<"INF ";
            }
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        FloydWarshall();
    }
    return 0;
}