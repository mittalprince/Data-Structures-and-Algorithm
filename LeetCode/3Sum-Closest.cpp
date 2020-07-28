// https://leetcode.com/problems/3sum-closest/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target) {
    int min_diff = INT_MAX;
    int n=nums.size();

    sort(nums.begin(), nums.end());
    int ans=0;

    for(int i=0; i<n; i++){
        int l = i+1;
        int r = n-1;

        while(l<r){
            int mid_sum = nums[i]+nums[l]+nums[r];

            int diff = abs(mid_sum-target);
            if(min_diff>diff){
                min_diff=diff;
                ans = mid_sum;
            }

            if(mid_sum == target) return mid_sum;

            if(mid_sum>target){
                r--;
            }
            else l++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}