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
    int n,m;
    cin>>n>>m;

    int arr[n][m];
    vector<int>v1(n+m-1), v0(n+m-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]){
                v1[i+j]++;
            }
            else v0[i+j]++;
        }
    }

    ll ans=0;
    for(int i=0; i<v1.size()/2; i++){
        ans += min(v1[i]+v1[n+m-2-i], v0[i]+v0[n+m-2-i]);
    }

    cout<<ans<<endl;
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}