#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int uniquePaths(int m, int n) {
    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0||j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}