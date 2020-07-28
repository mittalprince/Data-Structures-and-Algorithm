#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, t;
    cin>>n>>t;
    vector<int> arr(n);
    ip(arr, n);

    ll sum=0, l=0, ans=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        while(sum>t){
            sum -= arr[l++];
        }
        ans = max(ans, i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}