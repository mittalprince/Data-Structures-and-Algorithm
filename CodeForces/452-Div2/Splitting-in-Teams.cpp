// https://codeforces.com/contest/899/problem/A
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

void solve(){
    int n;
    cin>>n;
    int arr[2]={0};
    for(int i=0; i<n; i++){
        int x; cin>>x;
        arr[x-1]++;
    }

    if(arr[0] and arr[1]){
        ll ans = min(arr[0], arr[1]);
        arr[0] -= ans;
        if(arr[0]>0)ans += arr[0]/3;
        cout<<ans<<endl;
        return;
    }
    if(arr[0]==0)cout<<"0\n";
    else{
        cout<<arr[0]/3<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}