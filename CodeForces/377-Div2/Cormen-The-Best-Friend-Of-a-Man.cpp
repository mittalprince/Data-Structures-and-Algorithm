// https://codeforces.com/contest/732/problem/B
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
    ll opt1=0, opt2=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        opt1 += arr[i];
    }
    opt2=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]+arr[i-1]<k){
            arr[i] = k-arr[i-1];
        }
        opt2 += arr[i];
    }
    cout<<max(0ll, opt2-opt1)<<endl;
    op(arr, n);
    cout<<endl;
    return 0;
}