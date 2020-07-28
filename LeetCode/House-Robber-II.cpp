// https://leetcode.com/problems/house-robber-ii/
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

int rob(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    if(n==0)return 0;
    if(n==1)return nums[0];
    if(n==2)return max(nums[0],nums[1]);
    if(n==3)return max(nums[0],max(nums[1],nums[2]));

    vector<int>dp(n, 0);

    dp[0]=nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<n-1; i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }

    int ans = dp[n-2];
    dp[1]=nums[1];
    dp[2] = max(nums[1],nums[2]);

    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }

    ans = max(ans, dp[n-1]);
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