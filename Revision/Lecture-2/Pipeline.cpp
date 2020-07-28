// https://codeforces.com/contest/287/problem/B
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

ll func(ll n){
    return (n*(n+1))/2;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,k;
    cin>>n>>k;

    if(n==1){
        cout<<"0\n";
        return 0;
    }
    if(n<=k){
        cout<<"1\n";
        return 0;
    }
    
    ll max_output = func(k);

    if((max_output-(k-1))<n){
        cout<<"-1\n";
        return 0;
    }
    // debug(max_output);
    
    ll s=1, e=k;
    ll ans;
    while(s<=e){
        ll mid = s+(e-s)/2;
        // starting ke 2-mid  tak ke splitter ke output max_output se hta doo
        // qki humme min spliter use karne hai toh hum jayda output vale ko phela use karenge
        // taki kam spliter use hoo isliye strating ke mid spliter ka output remove kiya
        ll t = max_output - func(k-mid)-(mid-1);
        if(t>=n){
            ans = mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}