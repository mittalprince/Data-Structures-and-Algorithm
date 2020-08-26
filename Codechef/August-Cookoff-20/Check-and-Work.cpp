// https://www.codechef.com/COOK121B/problems/CHEFNWRK
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
    ll n,k;
    cin>>n>>k;

    vector<ll>arr(n);
    ip(arr, n);

    // sort(arr.begin(), arr.end());
    // reverse(arr.begin(), arr.end());
    
    bool flag=0;
    for(int i: arr){
        if(i>k){
            cout<<"-1\n";
            return;
        }
    }
    ll ans=0, sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum==k){
            ans++;
            sum=0;
        }
        if(sum>k){
            sum=0;
            i--;
            ans++;
        }
    }
    if(sum>0)ans++;
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