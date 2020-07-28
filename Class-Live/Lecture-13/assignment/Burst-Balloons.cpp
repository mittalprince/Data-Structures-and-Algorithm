#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[505][505];

int solve(vector<int>&arr, int n, int i, int j){
    if(i<0||j<i||i>=arr.size()||j>=arr.size()){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ans=INT_MIN;
    for(int k=i; k<=j; k++){
        int l = (i>0)?arr[i-1]:1;
        int r = (j<n-1)?arr[j+1]:1;

        int left = solve(arr, n, i, k-1);
        int right = solve(arr, n, k+1, j);

        ans = max(ans, arr[k]*l*r + (left+right));
    }
    return dp[i][j] = ans;
}

// recursive
int maxCoins(vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
    return solve(nums, nums.size(), 0, nums.size()-1);
}

// iterative
int maxCoins(vector<int>& nums) {
    int dp[505][505]={0};
    
    int n=nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    for(int d=1; d<=n; d++){
        int i=1, j=d;
        while(j<=n){
            int ans=INT_MIN;
            for(int k=i; k<=j; k++){
                ans = max(ans, dp[i][k-1]+dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);
            }
            dp[i][j]=ans;
            i++;
            j++;
        }
    }
    
    return dp[1][n];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}