// https://codeforces.com/contest/1148/problem/B
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

ll solve(ll arr[], ll n, ll target){
    ll s=0, e=n-1;
    if(arr[e]<target){
        return n; 
    }
    if(arr[s]>=target){
        return 0;
    }
    ll ans=0;
    while(s<=e){
        ll mid = s+(e-s)/2;
        if(arr[mid]>=target){
            ans = mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return ans;
}

int main(){
    fstIO;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;

    ll arr[n], brr[m];
    ip(arr, n);
    ip(brr, m);

    if(k>=n){
        cout<<"-1\n";
        return 0;
    }
    ll ans=0;
    for(ll i=0; i<=k; i++){
        ll idx = (solve(brr, m, arr[i]+ta))+(k-i);
        if(idx>=m){
            cout<<"-1\n";
            return 0;
        }
        ans = max(ans, brr[idx]+tb);
    }
    cout<<ans<<endl;
    return 0;
}