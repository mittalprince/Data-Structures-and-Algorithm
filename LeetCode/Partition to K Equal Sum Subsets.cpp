// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
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

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    if (k == 1) return true;
    if(n<k) return false;

    long long sum = 0;
    for(int i: nums) sum += i;
    if(sum % k) return false;

    int subset = sum / k;
    int subsetSum[k];
    bool taken[n];

    for (int i = 0; i < k; i++) subsetSum[i] = 0;
    for (int i = 0; i < n; i++) taken[i] = false;

    subsetSum[0] = nums[n - 1];
    taken[n - 1] = true;

    return canPartitionKSubsets(nums, subsetSum, taken, subset, k, n, 0, n-1);
}

bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
    if (subsetSum[curIdx] == subset) {
        if (curIdx == K - 2) return true;
        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
    }

    for (int i = limitIdx; i >= 0; i--) {
        if (taken[i]) continue;
        int tmp = subsetSum[curIdx] + nums[i];

        if (tmp <= subset) {
            taken[i] = true;
            subsetSum[curIdx] += nums[i];
            bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
            taken[i] = false;
            subsetSum[curIdx] -= nums[i];
            if (nxt) return true;
        }
    }
    return false;
}

/*
Time Complexity: O(2^(N * K)).
Because if we have K trees stacked on top of each other, the new height of the tree is K * n. i.e one subset is not independent from other.
Space Complexity: O(N).
Extra space is required for visited array.
*/

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

int n;
cin >> n;
vector<int> arr(n);

return 0;
}