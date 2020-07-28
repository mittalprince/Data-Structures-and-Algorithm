#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int maximalSquare(vector<vector<char>>& A) {
    int n=A.size();
    if(n==0) return 0;
    int m=A[0].size();
    if(m==0) return 0;


    if(n==0 || m==0) return 0;
    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    int len = 0 ;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i-1][j-1] == '1'){
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;
                len = max(len, dp[i][j]);
            }
        }
    }
    return len*len;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}