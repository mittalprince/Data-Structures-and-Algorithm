//https://leetcode.com/problems/maximum-length-of-repeated-subarray/
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

int findLength(vector<int>& a, vector<int>& b) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m = a.size(), n = b.size();
    if (!m || !n) return 0;
    vector<int> dp(n + 1);
    int res = 0;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            res = max(res, dp[j] = a[i] == b[j] ? 1 + dp[j + 1] : 0);
        }
    }
    return res;
}

int findLength(vector<int>& A, vector<int>& B) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=A.size();
    int m=B.size();
    
    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);
            }
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