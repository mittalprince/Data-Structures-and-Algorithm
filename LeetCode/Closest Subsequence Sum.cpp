// https://leetcode.com/problems/closest-subsequence-sum/
#include<iostream>
#include<vector>
#include<set>
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

set<int> left;
set<int> right;

void fillSet(vector<int>& nums, set<int>& result, int i, int sum) {
    if (i >= nums.size()) {
        result.insert(sum);
        return;
    }
    fillSet(nums, result, i+1, sum);
    fillSet(nums, result, i+1, sum+nums[i]);
}

int minAbsDifference(vector<int>& nums, int goal) {
    vector<int> left_nums(nums.begin(), nums.begin() + nums.size() / 2);
    fillSet(left_nums, left, 0, 0);
    vector<int> right_nums(nums.begin() + nums.size() / 2, nums.end());
    fillSet(right_nums, right, 0, 0);

    int min_diff = INT_MAX;
    for (int l : left) {
        int desired = goal - l;
        auto it = right.lower_bound(desired);
        if (it != right.end()) {
            min_diff = std::min(min_diff, std::abs(goal - (l + *it)));
        }
        if (it != right.begin()) {
            --it;
            min_diff = std::min(min_diff, std::abs(goal - (l + *it)));
        }
    }
    return min_diff;
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