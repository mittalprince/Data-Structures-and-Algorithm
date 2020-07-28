#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[25][2005];
int shift = 1001;

int solve(vector<int>&arr, int n, int i, int sum, int target){
    if(i==n){
        return sum == target;
    }

    if(dp[i][sum+shift] != -1) return dp[i][sum+shift];

    int opt1 = solve(arr, n, i+1, sum-arr[i], target);
    int opt2 = solve(arr, n, i+1, sum+arr[i], target);

    return dp[i][sum+shift] = opt1+opt2;
}

// recursive
int findTargetSumWays(vector<int>& nums, int S) {
    int n=nums.size();
    memset(dp, -1, sizeof(dp));

    return solve(nums, n, 0, 0, S);
}

// iterative
int findTargetSumWays(vector<int>& nums, int S) {
    int dp[25][2005]={0};
    //dp[i][j] => total ways to form j sum using i elemtns
    dp[0][nums[0]+1000] = 1;
    dp[0][-nums[0]+1000] +=1; // as if nums[0] is 0 it will point to same bucket

    for(int i=1; i<nums.size(); i++){
        for(int sum=-1000; sum<=1000; sum++){
            if(dp[i-1][sum+1000]>0){ // here we check if we have any ways to make this sum (sum+1000) with total i-t elemnt
                dp[i][sum+nums[i]+1000] += dp[i-1][sum+1000];
                // if we want to make sum+nums[i]+1000 sum using i elemnts, then we just check how many ways to we can make sum+1000 sum with i-1 elemnts
                // as till i-1 we have make sum+1000 sum and to include ith elemnt we can either substract it or add it. 
                dp[i][sum-nums[i]+1000] += dp[i-1][sum+1000];
            }
        }
    }

    return S>1000?0: dp[nums.size()-1][S+1000];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}