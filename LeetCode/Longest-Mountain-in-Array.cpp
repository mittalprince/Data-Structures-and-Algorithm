//https://leetcode.com/problems/longest-mountain-in-array/
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

int longestMountain(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    vector<int>up(n, 1), down(n,1);

    for(int i=n-2; i>=0; i--){
        if(A[i]>A[i+1]){
            down[i] = down[i+1]+1;
        }
    }

    int ans=0;
    for(int i=1; i<n; i++){
        if(A[i]>A[i-1])up[i] = up[i-1]+1;
    }

    for(int i=1; i<n-1; i++){
        if(up[i]>1 and down[i]>1){
            ans = max(ans, up[i]+down[i]-1);
        }
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