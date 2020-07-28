#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[105][105];
int n,m;
int solve(vector<vector<int>>&  A, int i, int j){
    if(j<0 || j>=m) return INT_MAX;

    if(i==(n-1)){
        return A[i][j];
    }
    if(dp[i][j] != -1) return dp[i][j];

    int opt1 = solve(A, i+1, j);
    int opt2 = solve(A, i+1,j+1);
    int opt3 = solve(A, i+1, j-1);

    return dp[i][j] = min(opt1, min(opt2, opt3))+A[i][j];
}
//recursive
int minFallingPathSum(vector<vector<int>>& A) {
    n=A.size();
    if(n==0) return 0;

    m=A[0].size();
    if(m==0) return 0;

    memset(dp, -1, sizeof(dp));
    int ans=INT_MAX;
    for(int i=0; i<m; i++){
        ans = min(ans, solve(A, 0, i));
    }
    return ans;
}

// iterative
int minFallingPathSum(vector<vector<int>>& A) {
    int n=A.size();
    int m = A[0].size();

    if(n==1 && m==1) return A[0][0];

    vector<vector<int>>dp(n, vector<int>(m, INT_MAX));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0){
                dp[i][j] = A[i][j];
            }
            else{
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if(j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if(j<m-1) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);

                dp[i][j] += A[i][j];
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0; i<m; i++){
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}