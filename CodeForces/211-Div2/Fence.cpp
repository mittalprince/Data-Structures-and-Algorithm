// https://codeforces.com/contest/363/problem/B
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    ip(arr, n);
    ll sum=0, curr=0;
    for(int i=0; i<k; i++){
        curr += arr[i];
    }
    int ans=0;
    sum =curr;
    for(int i=k; i<n; i++){
        curr -= arr[i-k];
        curr += arr[i];
        if(sum>curr){
            // cout<<sum<<" "<<curr<<" "<<i<<" "<<i-k+1<<endl;
            sum=curr;
            ans = i-k+1;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}