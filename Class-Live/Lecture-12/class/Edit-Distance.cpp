#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minDistance(string word1, string word2){
    int n=word1.length(), m=word2.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1, INT_MAX));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0||j==0){
                dp[i][j] = i+1;
            }
            else if(dp[i-1]==dp[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i][j], 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])));
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