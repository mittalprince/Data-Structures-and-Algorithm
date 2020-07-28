#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n,m;
    cin>>m;
    int coins[m];
    ip(coins, m);
    cin>>n;

    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    // dp[i][j]-> total ways if we req i amt of change using j types of coins

    for(int i=0; i<m; i++)
        dp[0][i]=1; // tw if we req 0 amt of changes

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            
            int opt1 = (i-coins[j]>=0)?dp[i-coins[j]][j]:0;//include
            int opt2 = (j>0)?dp[i][j-1]:0; // exclude

            dp[i][j]=opt2+opt1;
        }
    }

    cout<<dp[n][m-1]<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}