#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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

    int n;
    cin>>n;
    vector<int> arr(n), left(n+1, INT_MIN), right(n+1, INT_MAX);
    
    ip(arr, n);

    for(int i=1; i<=n; i++){
        left[i] = max(left[i-1], arr[i-1]);
    }

    for(int i=n-1; i>=0; i--){
        right[i] = min(right[i+1], arr[i]);
    }

    int ans=1;
    for(int i=1; i<n; i++){
        if(left[i]<=right[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}