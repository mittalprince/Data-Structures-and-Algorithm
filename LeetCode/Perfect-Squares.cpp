// https://leetcode.com/problems/perfect-squares/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int numSquares(int n) {
    if(n<4)return n;
    vector<int> dp(n+1, INT_MAX);
    dp[0]=0, dp[1]=1, dp[2]=2, dp[3]=3;

    for(int i=4; i<=n; i++){
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}