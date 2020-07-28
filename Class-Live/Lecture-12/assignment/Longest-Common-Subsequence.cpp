#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int longestCommonSubsequence(string text1, string text2) {
     int n = text1.size();
    int m = text2.size();
    int dp[n+1][m+1];
    for(int i = 0; i <=n; i++ ){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
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