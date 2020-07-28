#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

int n, target;
int arr[105]={0};
ll dp[105][MAX]={0};

ll ways(int i, int sum){
    if(i==n) return sum==target;

    if(dp[i][sum] != -1) return dp[i][sum];
    int opt1 = ways(i+1, sum);
    int opt2 = ways(i+1, sum+arr[i]);

    return dp[i][sum] = (opt1+opt2);
}

// void bottomUp(){
//     ll dp[105][MAX]={0};
//     for(int i=0; i<=n; i++){
//         for(int j=0; j<=target; j++){
//             if(j==0){
//                 dp[i][j]=1;
//             }
//             else if(i==0) dp[i][j]=1;
//             else if(arr[i-1]<=j){
//                 dp[i][j] = dp[i-1][j]+dp[i][j-arr[i-1]];
//             }
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     cout<<dp[n][target]<<endl;
// }

void solve(){
    cin>>n>>target;
    ip(arr, n);
    memset(dp, -1, sizeof(dp));
    cout<<ways(0, 0)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}