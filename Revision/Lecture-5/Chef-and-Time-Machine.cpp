// https://www.codechef.com/problems/CHEFTMA
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

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int>a(n), b(n), c(k+m);
    ip(a, n);
    ip(b, n);
    ip(c, k+m);

    vector<int>diff(n);
    ll ans=0;
    for(int i=0; i<n; i++){
        diff[i] = a[i]-b[i];
        ans += diff[i];
    }
    sort(diff.begin(), diff.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    for(int i=0, j=0; i<c.size() and j<diff.size(); i++){
        if(diff[j]>=c[i]){
            ans -= c[i];
            j++;
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