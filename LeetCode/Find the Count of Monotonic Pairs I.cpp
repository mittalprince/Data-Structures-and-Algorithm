// https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/
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

const int mod = 1e9+7;
int solve(vector<int>&nums, int i, int x, int y, vector<vector<vector<int>>>&dp){
    if(i>= nums.size())return 1;
    if(dp[i][x][y] != -1)return dp[i][x][y];

    int ans = 0;
    for(int j=x; j<=nums[i]; j++){
        if(nums[i]-j <= y){ // not understand why <= not =
            ans = (ans + solve(nums, i+1, j, nums[i]-j, dp))%mod;
        }
    }
    return dp[i][x][y] = ans%mod;
}

int countOfPairs(vector<int>& nums) {
    int ans=0;
    int n = nums.size();
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(51, vector<int>(51, -1)));
    return solve(nums, 0, 0, nums[0], dp);
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}