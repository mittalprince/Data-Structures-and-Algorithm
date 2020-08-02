#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 3000

ll n;
double arr[MAX];
double dp[MAX][MAX];

double solve(int coins, int req_head){
    if(req_head == 0) return 1;
    if(coins == 0) return 0;

    if(dp[coins][req_head] > -1) return dp[coins][req_head];

    double opt1 = arr[coins]*solve(coins-1, req_head-1);
    double opt2 = (1-arr[coins])*solve(coins-1, req_head);

    dp[coins][req_head] = opt1+opt2;
    return dp[coins][req_head];
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<fixed<<setprecision(11)<<solve(n, (n+1)/2)<<endl;
}

int main(){
    cin>>n;
    ip(arr, n);
    topDown();
    return 0;
}