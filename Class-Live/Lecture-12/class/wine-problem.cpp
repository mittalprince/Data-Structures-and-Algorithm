#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2005

ll n;
ll arr[MAX];
ll dp[MAX][MAX];
//dp[i][j] -> what will be max profit if i can sell either ith or jth bottle
// ans will be at dp[0][n] -> iterative

ll solve(ll i, ll j, ll day){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll opt1 = arr[i]*day+solve(i+1, j, day+1);
    ll opt2 = arr[j]*day+solve(i, j-1, day+1);

    dp[i][j] = max(opt1, opt2);
    return dp[i][j];
}

void recurrsive(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, n-1, 1)<<endl;
}

void iterative(){
    memset(dp, 0, sizeof(dp));
    for(int i=n; i>=0; i--){
        for(int j=0; j<=n; j++){
            if(i>j) dp[i][j]=0;
            else{
                ll curr_day = n-(j-i);
                ll opt1 = arr[i]*curr_day + dp[i+1][j];
                ll opt2 = arr[j]*curr_day + dp[i][j-1];
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    cout<<dp[0][n]<<endl;
}
int main(){
    cin>>n;
    ip(arr, n);
    // recurrsive();
    iterative();
    return 0;
}