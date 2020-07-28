#include<iostream>
#include<vector>
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

bool isPossilbe(ll dist[], ll n, ll c, ll min_dist){
    ll cows=1;
    ll curr_stall=dist[0];
    for(int i=1; i<n; i++){
        ll x = dist[i];
        if((x-curr_stall)>=min_dist){
            cows++;
            curr_stall=x;
            if(cows == c){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    ll n,c;
    cin>>n>>c;
    ll dist[n];
    ip(dist, n);

    sort(dist, dist+n);
    ll s=dist[0], e=dist[n-1]-dist[0]; // max dist between cows will be dist[n-1]-dist[0]

    ll ans=0;
    while(s<=e){
        ll mid = s+(e-s)/2;
        if(isPossilbe(dist, n, c, mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}