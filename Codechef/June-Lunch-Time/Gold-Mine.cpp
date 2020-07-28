#include<iostream>
#include<vector>
#include<iomanip>
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

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n),b(n),g(n);

    for(ll i=0; i<n; i++){
        cin>>g[i]>>a[i]>>b[i];
    }

    cout<<fixed<<setprecision(12);

    double chef_days=0, chefu_days=0;

    for(ll i=0; i<n; i++){
        double t = (double)g[i]/((double)(a[i]+b[i]));
        chef_days += (double)b[i]*t;
        chefu_days += (double)a[i]*t;
    }

    cout<<chef_days<<" "<<chefu_days<<endl;
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