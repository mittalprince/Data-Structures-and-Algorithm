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
    ll n,x;
    cin>>n>>x;

    ll arr[n];
    ll sum=0;
    ll l=-1,r;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]%x){
            if(l==-1)l=i;
            r=i;
        }
        sum += arr[i];
    }
    if(sum%x){
        cout<<n<<endl;
    }
    else if(l==-1){
        cout<<"-1\n";
    }
    else{
        cout<<max(n-l-1, r)<<endl;
    }

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