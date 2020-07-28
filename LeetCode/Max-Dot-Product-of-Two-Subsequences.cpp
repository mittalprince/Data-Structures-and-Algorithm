#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given two arrays nums1 and nums2.
Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
A subsequence of a array is a new array which is formed from the original array by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).
*/

int dp[505][505][2];

int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, int l){
    if(i>=nums1.size() || j>=nums2.size()){
        if(l==1) return 0;
        else return -1;
    }
    
    if(dp[i][j][l] != -1) return dp[i][j][l];
    
    int opt1 = nums1[i]*nums2[j] + solve(nums1, nums2, i+1, j+1, 1);
    int opt2 = solve(nums1, nums2, i+1, j, l);
    int opt3 = solve(nums1, nums2, i, j+1, l);
    
    return dp[i][j][l] = max(opt1, max(opt2, opt3));
}

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    memset(dp, -1, sizeof(dp));
    int ans = solve(nums1, nums2, 0, 0, 0);
    if(ans == -1){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        return max(nums1.front()*nums2.back(), nums1.back()*nums2.front());
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}