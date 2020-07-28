#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool solve(vector<int>&arr, int i, int sum){
    if(i>=arr.size()||sum<arr[i]) return false;
    if(sum == arr[i]) return true;

    return solve(arr, i+1, sum-arr[i])||solve(arr, i+1, sum);
}

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i: nums){
        sum += i;
    }
    if(sum&1) return false;
    sort(nums.rbegin(),nums.rend());
    return solve(nums, 0, sum/2);
}

// iterative
bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i: nums){
        sum += i;
    }
    if(sum&1) return false;
    
    sum /= 2;
    int n=nums.size();
    
    vector<vector<int>>dp(sum+1, vector<int>(n+1, 0));
    
    for(int i=0; i<=n; i++){
        dp[0][i]=1;
    }
    
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            
            if(nums[j-1]<=i){
                dp[i][j] = dp[i][j]||dp[i-nums[j-1]][j-1];
            }
        }
    }
    
    return dp[sum][n];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}