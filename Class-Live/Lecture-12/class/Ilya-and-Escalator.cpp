#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

double dp[2001][2001]={0};
int n,t;
double p;

double solve(){
    dp[0][0]=1;
    // dp[i][j] -> prob of standing j person on escalator at time t

    for(int i=1; i<=t; i++){
        for(int j=0; j<=n; j++){
            if(j==n){
                // when we are at nth people
                // 1. we have till n-1 person so he will come then dp[i][j] = p*dp[i-1][j-1]
                // we have already n, then we dont have option we just ask for prev time (i-1)
                dp[i][j] = p*dp[i-1][j-1] + dp[i-1][j];
            }
            else if(j==0){
                // when person don't come on escalator, then dp[i][j] -> (1-p)*dp[i-1][j]
                // i.e what is prob with same no of person but with prev time
                dp[i][j] = (1-p)*dp[i-1][j];
            }
            else{
                // here we have two options
                // 1. preson will come into escalator then dp[i][j] = p*pd[i-1][j-1] (on prev time and one person less)
                // 2. he will not come, then we just consider dp[i-1][j] with prod of (1-p)
                dp[i][j] = p*dp[i-1][j-1] + (1-p)*dp[i-1][j];
            }
        }
    }

    double ans=0;
    for(int i=0; i<=n; i++){
        ans += i*dp[t][i];
    }
    return ans;
}
int main(){
    cin>>n>>p>>t;
    cout<<fixed<<setprecision(8)<<solve()<<endl;   
    return 0;
}