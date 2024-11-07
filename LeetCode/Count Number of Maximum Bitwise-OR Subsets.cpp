// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
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

int solve(vector<int>&nums, int i, int curr_or, int& max_or){
    if(i==nums.size())return curr_or == max_or;
    int take = solve(nums, i+1, curr_or | nums[i], max_or);
    int skip = solve(nums, i+1, curr_or , max_or);
    return take + skip;
}
int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0;
    for(int i: nums) maxOr |= i;
    return solve(nums, 0, 0, maxOr);
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