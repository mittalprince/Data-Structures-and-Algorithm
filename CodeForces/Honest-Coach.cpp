#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n;
    cin>>n;
    int arr[n];

    ip(arr, n);
    sort(arr, arr+n);

    int ans=INT_MAX;
    for(int i=1; i<n; i++){
        ans = min(ans, arr[i]-arr[i-1]);
    }

    cout<<ans<<endl;

}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}