//https://leetcode.com/problems/jump-game-v/
#include<iostream>
#include<vector>
#include<cstring>
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
int dp[1005];

int solve(vector<int>&arr, int n, int i, int d){
    if(i<0 || i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    int ans=1;
    for(int j=i+1; j<min(n, i+d+1) && arr[j]<arr[i]; j++){
        ans = max(ans, 1+solve(arr, n, j, d));
    }

    for(int j=i-1; j>=max(0, i-d) && arr[j]<arr[i]; j--){
        ans = max(ans, 1+solve(arr, n, j, d));
    }
    return dp[i] = ans;
}

int maxJumps(vector<int>& arr, int d) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int ans=0;

    int n=arr.size();
    if(n==1) return 1;

    for(int i=0; i<n; i++){
        ans = max(ans, solve(arr, n, i, d));
    }

    return ans;
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