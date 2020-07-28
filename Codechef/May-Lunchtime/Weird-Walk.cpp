#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

void solve(){
    int n;
    cin>>n;
    int a[n], b[n];
    ip(a, n);
    ip(b, n);

    ll pa=0, pb=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(a[i] == b[i] && pa==pb){
            ans += a[i];
        }
        pa += a[i];
        pb += b[i];
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