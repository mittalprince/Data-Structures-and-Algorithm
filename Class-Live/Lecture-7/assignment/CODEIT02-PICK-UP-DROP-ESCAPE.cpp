#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int ans=INT_MIN;

void findMaxXor(int arr[], int n, int i, int k, int curr){
    if(i==n && k==0){
        ans = max(ans, curr);
        return;
    }
    if(i>=n || k<0) return;
    
    findMaxXor(arr, n, i+1, k, curr);
    findMaxXor(arr, n, i+1, k-1, curr^arr[i]);
}
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    ip(arr, n);
    ans = INT_MIN;
    findMaxXor(arr, n, 0, k, 0);
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