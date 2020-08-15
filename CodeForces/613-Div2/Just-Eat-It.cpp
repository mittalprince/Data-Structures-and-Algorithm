// https://codeforces.com/contest/1285/problem/B
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
    bool flag=true;

    vector<int>arr(n);
    ip(arr,n);

    ll sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum<=0){
            cout<<"NO\n";
            return;
        }
    }
    sum=0;
    for(int i=n-1; i>=0; i--){
        sum += arr[i];
        if(sum<=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

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