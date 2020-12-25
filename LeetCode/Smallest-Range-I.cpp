//https://leetcode.com/problems/smallest-range-i/
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

int smallestRangeI(vector<int>& A, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mx=A[0], mn=A[0];
    for(int i=0; i<A.size(); i++){
        mx = max(mx, A[i]);
        mn = min(mn, A[i]);
    }

    return max(0, mx-mn-2*k);
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