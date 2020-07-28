#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int maximalSquare(vector<vector<char>>& matrix) {
    int n=matrix.size();
    if(n==0) return 0;
    int m=matrix[0].size();
    if(m==0) return 0;
    
    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    int maxsqlen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i-1][j-1] == '1'){
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                maxsqlen = max(maxsqlen, dp[i][j]);
            }
        }
    }
    return maxsqlen*maxsqlen;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> >arr(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    cout<<maximalSquare(arr)<<endl;
    return 0;
}