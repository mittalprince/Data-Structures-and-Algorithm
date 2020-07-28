// https://leetcode.com/problems/4sum/
#include<iostream>
#include<vector>
#include<algorithm>
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

class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int>&nums, int target, int start){
        vector<vector<int>>res;
        int s=start, e=nums.size()-1;
        
        while(s<e){
            if(nums[s]+nums[e]<target or (s>start and nums[s]==nums[s-1])){
                s++;
            }
            else if(nums[s]+nums[e]>target or (e<nums.size()-1 and nums[e]==nums[e+1])) e--;
            else res.push_back({nums[s++], nums[e--]});
        }
        return res;
    }
    
    vector<vector<int>> ksum(vector<int>&nums, int target, int start, int k){
        vector<vector<int>>res;
        if(start == nums.size() or nums[start]*k>target or nums.back()*k<target){
            return res;
        }
        
        if(k==2){
            return twoSum(nums, target, start);
        }
        
        for(int i=start; i<nums.size(); i++){
            if(i==start or nums[i] != nums[i-1]){
                for(auto it: ksum(nums, target-nums[i], i+1, k-1)){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(it), end(it));
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        return ksum(nums, target, 0, 4);
    }
};

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>res;

    if(nums.empty())return res;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        if(i>0 and nums[i] == nums[i-1])continue;

        for(int j=i+1; j<nums.size(); j++){
            if(j>i+1 and nums[j] == nums[j-1])continue;

            int s=j+1;
            int e=nums.size()-1;

            while(s<e){
                int sum = nums[s]+nums[e]+nums[i]+nums[j];
                if(sum == target){
                    res.push_back({nums[i],nums[j],nums[s],nums[e]});
                    while(s<e and nums[s] == nums[s+1])s++;
                    while(e>s and nums[e]==nums[e-1])e--;
                    s++;
                    e--;
                }
                else if(sum>target) e--;
                else s++;
            }
        }
    }
    return res;
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