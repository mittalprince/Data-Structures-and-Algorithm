#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 3005
#define mod 1000000007

ll dp[MAX][MAX]={0};
int n;
char arr[MAX];

int main(){
    cin>>n;
    string s;
    cin>>s;

    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;

    // dp[i][j] = dp[i-1][0] + ... + dp[i-1][j-1] <
    // dp[i][j] = dp[i-1][j] + ... + dp[i-1][i-1] >

    // The idea is that dp[i][j] holds the number of
    // ways to form a permutation of (0, 1, ..., i-1) satisfying
    // the < and > constraints and ending with j.

    for (int i = 1; i < n; i++){
        if(s[i-1] == '<'){
            for(int j=1; j<=i; j++){
                dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%mod;
            }
        }
        else{
            for(int j=i-1; j>=0; j--){
                dp[i][j] = (dp[i][j+1]+dp[i-1][j])%mod;
            }
        }
    }
    

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}