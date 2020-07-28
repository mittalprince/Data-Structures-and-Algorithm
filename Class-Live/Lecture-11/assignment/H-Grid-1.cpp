#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000
#define mod 1000000007

int main(){
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    ll dp[MAX][MAX];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '#'){
                dp[i][j]=0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            if(i>0) dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
            if(j>0) dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}