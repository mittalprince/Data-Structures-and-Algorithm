#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define mod 1000000007

ll dp[105][MAX] = {0};
// dp[i][j] -> no of ways to dist j candies in first i children
// total ways to dist o candies in 0 children is 1 dp[0][0]=1;
// whereas total ways to dist 0 cand in i(i>0) child is 0 as we cant give them any candy

/*
now dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j-2]+....+dp[i-1][j-arr[i]] (till when i-arr[i] exist)
explanation: -> we check hoe mays to dist j candies in i-1 children + no of ways to dist j-1 candies to i-1 children and son on
as we can dist 0 to arr[i] candies to each ith child, bcoz of this we check (i-1,k)+(i-1,k-1)+ .. 

Now:

dp[i][k] = dp[i-1][k]+ (dp[i-1][k-1]+...+dp[i-1][k-arr[i]])
dp[i][k-1] = (dp[i-1][k-1]+dp[i-1][k-2]+...+dp[i-1][k-arr[i]]) + dp[i-1][k-1-arr[i]];

using these we can fig that:
(dp[i-1][k-1]+...+dp[i-1][k-arr[i]]) = dp[i][k-1]-dp[i-1][k-arr[i]-1]

hence dp[i][k] = dp[i-1][k]+dp[i][k-1]-dp[i-1][k-arr[i]-1];
*/

int *arr;

int main(){
    int n, k;
    cin>>n>>k;
    arr = new int[n+1];
    ip(arr, n);
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(i==0){
                if(j==0) dp[i][j]=1;
                else dp[i][j]=0;
            }
            else if(j==0){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = (mod+dp[i-1][j]+dp[i][j-1] -((j-arr[i]-1)>=0?dp[i-1][j-arr[i]-1]:0))%mod;
            }
        }
    }

    cout<<dp[n][k]<<endl;
    return 0;
}