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

bool isPossible(vector<ll>height, ll n, ll m, ll min_height){
    ll extra_height=0;
    for(ll i=0; i<n; i++){
        if(height[i]>min_height){
            extra_height += height[i]-min_height;
        }

        if(extra_height >= m){
            return true;
        }
    }
    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    ip(arr, n);

    sort(arr.begin(), arr.end());
    ll s=arr[0];
    ll e=arr[n-1];

    ll ans=0;
    while(s<=e){
        ll mid = s+(e-s)/2;
        if(isPossible(arr, n, m, mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}