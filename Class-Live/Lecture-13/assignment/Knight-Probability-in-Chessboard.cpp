#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

double dp[30][30][105];
int x[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

double solve(int n, int i, int j, int k){

    if(i<0||j<0||i>=n||j>=n) return 0;
    if(k==0) return 1;

    if(dp[i][j][k] > -1) return dp[i][j][k];

    double ans=0;
    for(int p=0; p<8; p++){
        ans += solve(n, i+x[p], j+y[p], k-1);
    }

    ans = ans/8;

    return dp[i][j][k]=ans;
}

double knightProbability(int N, int K, int r, int c) {
    memset(dp, -1, sizeof(dp));
    return solve(N, r, c, K);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}