#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

//use logic of LCS
int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int n=A.size(), m=B.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0||j==0) dp[i][j]=0;
            else if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] =max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}