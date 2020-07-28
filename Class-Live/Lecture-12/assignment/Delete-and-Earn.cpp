#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<pair<int, int>, int>dp;
map<int, int> freq;

int solve(int i, int n, vector<int>&nums){
    if(i==n){
        return 0;
    }
    
    if(dp.find({nums[i], freq[nums[i]]}) != dp.end()){
        return dp[{nums[i], freq[nums[i]]}];
    }
    
    int prev_no_freq = freq[nums[i]-1];
    int next_no_freq = freq[nums[i]+1];
    freq[nums[i]-1]=freq[nums[i]+1] = 0;
    
    int opt1 = nums[i]*freq[nums[i]]+solve(i+1, n, nums);
    freq[nums[i]-1] = prev_no_freq;
    freq[nums[i]+1] = next_no_freq;
    
    int opt2 = solve(i+1, n, nums);
    
    return dp[{nums[i], freq[nums[i]]}] = max(opt1, opt2);
}

// recursaive
int deleteAndEarn(vector<int>& nums) {
    for(int i: nums){
        freq[i]++;
    }
    
    vector<int>arr;
    for(auto it: freq){
        arr.push_back(it.first);
    }
    int n = freq.size();
    return solve(0, n, arr);
}

// iterative
int deleteAndEarn(vector<int>& nums) {
    int arr[20005]={0};
    for(int i: nums){
        arr[i]++;
    }

    int dp[20005]={0};
    dp[1]=arr[1];

    for(int i=2; i<=20001; i++){
        dp[i] = max(dp[i-1], dp[i-2]+(arr[i]*i));
    }

    return dp[20001];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}