// ROHAAN - Defend The Rohan
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
#define MAX 55

ll n;

ll solve(){
    cin>>n;
    vector<vector<ll> >dist(n, vector<ll>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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

    ll q, ans=0;
    cin>>q;
    while(q--){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        ans += dist[u][v];
    }

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t, tc=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<tc++<<": ";
        cout<<solve()<<endl;
    }
    return 0;
}