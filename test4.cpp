#include<iostream>
#include<vector>
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

bool isPossible(vector<int>arr, ll mid, int h){
    int ct=0;
    for(int i:  arr){
        ct += i/mid;
        if(i%mid)ct++;
    }
    return ct<=h;
}
void solve(){
    int n,h;
    cin>>n>>h;
    vecto<int>arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];

    int s=0,e=h;
    while(s<e){
        ll mid = (s+e)/2;
        if(isPossible(arr, mid, h)){
            e=mid;
            ans = mid;
        } else s=mid-1;
    }
    cout<<ans<<endl;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}