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

/*
Logic: Sorting

Our task is make the min of arr >= max of brr
So we first sort arr and brr in reverse order

Now take one by one item from both and add brr[i]-arr[i] into ans if brr[i]>arr[i]
Why since we make min(arr)>=max(brr) so if brr[i]>arr[i] (assume 5>1) then their diff is 4
and we make 5 to 2 and 1 to 3, so when we arise condition brr[i]>arr[i] we make brr[i] just smaller than
arr[i] so that min(arr)>=max(brr) in min operations.
*/
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<int> arr(n), brr(m);
    ip(arr, n);
    ip(brr, m);

    sort(arr.begin(), arr.end());
    sort(brr.rbegin(), brr.rend());

    int len = min(n,m);
    ll ans=0;
    for(int i=0; i<len; i++){
        if(brr[i]>arr[i]){
            ans += brr[i]-arr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}