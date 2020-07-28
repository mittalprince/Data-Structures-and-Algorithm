#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<int, vector<int>>dp;
// dp[i] -> gives the list of element that completely divides nums[i]
// use concept of LIS
// for a given element we check al prev elemnts that divides nums[i] and append its vector
// into d[i] list 

vector<int> solve(vector<int>& nums, int i){
    if(dp.count(i)) return dp[i];

    vector<int>ans;
    for(int j=0; j<i; j++){
        if(nums[i]%nums[j] == 0){
            vector<int> t = solve(nums, j);
            if(ans.size()<t.size()){
                ans = t;
            }
        }
    }
    ans.push_back(nums[i]);
    return dp[i] = ans;
}
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());

    vector<int>ans;
    for(int i=0; i<n; i++){
        vector<int>t = solve(nums, i);
        if(ans.size() < t.size()) ans=t;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}