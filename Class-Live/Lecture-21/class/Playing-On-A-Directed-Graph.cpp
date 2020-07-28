#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

ll n,m;
ll dist[505][505], ans[505];

int main(){
    fstIO

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = inf;
        }
        dist[i][i]=0;
        ans[i] = inf;
    }

    for(int i=0; i<m; i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dist[i][i]<0){
            // debug(dist[i][i])
            cout<<"NO"<<endl;
            return 0;
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans[j] = min(ans[j], dist[i][j]);
        }
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++){
        cout<<ans[i];
        if(i!=n) cout<<" ";
        else cout<<endl;
    }
    return 0;
}