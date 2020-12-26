//https://leetcode.com/problems/smallest-range-ii/
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

int smallestRangeII(vector<int> A, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    sort(A.begin(), A.end());

    int mx=A[n-1], mn=A[0], ans = mx-mn;

    for(int i=0; i<n-1; i++){
        mx = max(mx, A[i]+2*k);
        mn = min(A[i+1], A[0]+2*k);
        ans = min(ans, mx-mn);
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}