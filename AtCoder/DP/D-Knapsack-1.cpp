#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

ll n,capacity;
ll price[100], wt[100];
ll dp[105][MAX];

void bottomUp(){
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(j>=wt[i-1]){
                dp[i][j] = max(dp[i-1][j], price[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][capacity]<<endl;
}

ll solve(int i, int j){
    if(i==0||j==0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(wt[i-1]>j) return dp[i][j] = solve(i-1, j);

    return dp[i][j] = max(solve(i-1, j), price[i-1]+solve(i-1, j-wt[i-1]));
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(n, capacity)<<endl;
}

int main(){
    cin>>n>>capacity;
    for(int i=0; i<n; i++){
        cin>>wt[i]>>price[i];
    }
    // bottomUp();
    topDown();
    return 0;
}