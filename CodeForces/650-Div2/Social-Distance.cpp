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
    int n,k, i=0;
    cin>>n>>k;

    string s;
    cin>>s;
    ll ans=0;

    while(i<n){
        bool present=false;
        for(int j=i; j<=i+k and j<n; j++){
            if(s[j] == '1'){
                present=true;
                i = j+k+1;
                break;
            }
        }
        if(!present){
            ans++;
            i += k+1;
        }
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