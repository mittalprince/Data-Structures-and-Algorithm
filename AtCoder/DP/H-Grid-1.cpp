#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define MAX 1002

int n,m;
ll dp[MAX][MAX];
char arr[MAX][MAX];

void bottomUp(){
    memset(dp, 0, sizeof(dp));

    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '#'){
                dp[i][j]=0;
                continue;
            }
            if(i>0) dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
            if(j>0) dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}

ll solve(int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0||j<0) return 0;
    if(arr[i][j] == '#'){
        dp[i][j]=0;
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];
    
    return dp[i][j] = (solve(i-1, j)+solve(i, j-1))%mod;
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(n-1, m-1)<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    // bottomUp();
    topDown();
    return 0;
}