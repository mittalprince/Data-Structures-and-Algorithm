// https://www.codechef.com/ENAU2020/problems/ECAUG205
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

ll n,k;
ll *arr;

bool canPossible(ll mid){
    ll ct=0;
    for(int i=0; i<n; i++){
        ct += arr[i]/mid;
        if(ct>=k)return true;
    }

    return ct>=k;
}

void solve(){
    cin>>n>>k;
    arr = new ll[n];
    ip(arr, n);
    sort(arr, arr+n);

    ll l=0, r=arr[n-1];
    ll ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(mid==0)break;
        if(canPossible(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
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