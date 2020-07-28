// https://leetcode.com/problems/combination-sum-iv/
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

int combinationSum4(vector<int>& nums, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<uint32_t> dp(target + 1);
    dp[0] = 1;
    sort (nums.begin(), nums.end());
    for (int i = 1; i <= target; i++) {
        for (auto num : nums) {
            if (i < num) break;
            dp[i] += dp[i - num];
        }
    }

    return dp[target];
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