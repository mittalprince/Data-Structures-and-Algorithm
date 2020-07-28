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

void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
 
    bool flag=false;
    ll ans=0, min_u, max_v;
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        if(!flag){
            if(u<=x and x<= v){
                min_u=u;
                max_v=v;
                flag=true;
            }
        }
        else{
            if(u<=min_u and v>=min_u){
                min_u=u;
            }
            if(u<=max_v and v>=max_v){
                max_v=v;
            }
        }
    }
    if(!flag){
        cout<<"1\n";
        return;
    }
    ans = max_v-min_u+1;
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