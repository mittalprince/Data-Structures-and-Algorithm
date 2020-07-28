#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2005
#define mod 998244353

ll dp[MAX][MAX]={0};
// dp[i][j] -> total ways when we have total i bricks and out of them j bricks have different color from its left brick
int n, m, k;

void sovle(){
    // total ways when i have 1 brick and out of them 0 bricks have diff color from its left bricks
    // will be m (different color that i can make on bricks)
    // as we have single brick and each have diff color from right (as there are 0 bricks on its right, so k will be 0)
    // ans will be total ways of such arrange that is m.
    dp[1][0]=m;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            // now we have here two options
            //1. consider i-1 bricks which have j bricks that has color diff from its left
            //2. consdier (i-1)bricks which have j-1 bricks that has color diff from its left and
            //   but we req j bricks so for the ith brick we have total (m-1) color such that ith brick 
            //   color will not match with i-1th brick, so multiply with (m-1) [means i have m-1 options]
            dp[i][j] = (dp[i-1][j]%mod + (dp[i-1][j-1]*(m-1)%mod))%mod;
        }
    }
    cout<<dp[n][k]<<endl;
}
int main(){
    cin>>n>>m>>k;
    sovle();
    return 0;
}